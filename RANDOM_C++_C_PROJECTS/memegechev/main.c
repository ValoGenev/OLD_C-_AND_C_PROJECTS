#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

#define true 1
#define false 0

/*struktura za opisanie na tyrsenite v programata broi na operatorite i broi znacheshti simvoli */
typedef struct {
   int doCount; /* broi na operatorite DO/WHILE */
   int whileCount; /* broi na operatorite WHILE */
   int forCount; /* broi na operatorite FOR */
   size_t maxLen; /* broq simvoli v nai-dylgiq red */
   size_t currentLineLen; /* nomera na nai-dylgiq red */
   int maxLenNum; /* polzva se pri izchisleniqta - broq simvoli v tekushtiq red */
} EXPRESSION_STATS, * PEXPRESSION_STATS;

typedef struct EXPR_PROC_DATA EXPR_PROC_DATA;

/* opisanie na dannite, nujni za obrabotvane na redovete ot programata */
typedef struct EXPR_PROC_DATA {
   char * buffer; /* bufer v koito shte se chete programata red po red */
   int bufferSize; /* golemina na bufera */
   void * dataSource;  /* iztochnik na dannite - file, masiv, klaviatura... */
   int dataSourceSize;  /* razmer na iztochnika - ima smisyl samo za masiv */
   void (*reader) (EXPR_PROC_DATA * data, int currLine, int * endOfData); /* ukazatel kym funkciq, koqto shte obrabotva iztochnika na danni za da popylni bufera */
} * PEXPR_PROC_DATA;

/* proverqva dali niza str zapochva sys zadadeniq v token niz.
 Uslovieto za sydyrjimost e dumite da syvpadat napylno kakto po nabor ot simvvoli, taka i po dyljina */
int ContainsToken(const char * str, const char * token, int * tokenLen)
{
   int res = !strncmp(str, token, strlen(token)) && ((strlen(str) == strlen(token)) ||
      (!isdigit(str[strlen(token)]) && !isalpha(str[strlen(token)])));

   *tokenLen = res ? strlen(token) : 0;

   return res;
}

/* izchistva ot expression vsichki nevalidni za edna programa simvoli - tova donqkyde optimizira pretyrsvaneto za operatori,
 a syshto taka reshava problema s razdelite za nov red */
int FlushInvalidChars(char ** expression) {
   int res = 0;
   while (expression && **expression && (**expression==' ' || **expression <= 27 || isdigit(**expression))) {
      if (isdigit(**expression))
         res++;
      (*expression)++;
   }

   return res;
}

/* nulira statistikata za broq operatori v programata */
void InitStats(PEXPRESSION_STATS stats) {
   stats->doCount = 0;
   stats->whileCount = 0;
   stats->forCount = 0;
   stats->maxLen = 0;
   stats->maxLenNum = 0;
   stats->currentLineLen = 0;
};

/* funkciq, koqto se izpolzva za obrabotvane na danni ot masiv. currLine se izpolzva kato indeks za masiva,
a endOfData posochva koga e dannite sa privyrshili */
void ArrayReader(EXPR_PROC_DATA * data, int currLine, int * endOfData) {
   if (currLine >= data->dataSourceSize)
      *endOfData = true;
   else {
      strncpy(data->buffer, (const char *) ((char **)(data->dataSource))[currLine], data->bufferSize - 1);
      data->buffer[data->bufferSize - 1] = 0;
      *endOfData = false;
   }
}

/* funkciq, koqto se izpolzva za obrabotvane na danni ot klaviaturata. currLine se izpolzva kato nomer na red (v sluchaq ne e napraveno taka),
a endOfData posochva koga e dannite sa privyrshili */
void KeyboardReader(EXPR_PROC_DATA * data, int currLine, int * endOfData) {
   printf("%d) ", currLine + 1);
   fgets(data->buffer, data->bufferSize, stdin);
   *endOfData = feof(stdin);
   if (!(*endOfData))
      *endOfData = !strncmp(data->buffer, "END", 3);
}

/* funkciq, koqto se izpolzva za obrabotvane na danni ot proizvolen potok - file ili klaviatura.
currLine ne se izpolzva, a endOfData posochva koga e dannite sa privyrshili */
void StreamReader(EXPR_PROC_DATA * data, int currLine, int * endOfData) {
   FILE * stream;
   stream = (FILE *) data->dataSource;
   fgets(data->buffer, data->bufferSize - 1, stream);
   *endOfData = feof(stream);
}

/* izvejdane statistikata za obrabotenata programa v potok - file ili ekran */
void WriteStats(PEXPRESSION_STATS stats, FILE * out) {
   fprintf(out, "Broi na operatorite: \n");
   fprintf(out, "  do/while: %d\n", stats->doCount);
   fprintf(out, "  while: %d\n", stats->whileCount);
   fprintf(out, "  for: %d\n", stats->forCount);
   fprintf(out, "-----------\n");
   fprintf(out, "Nomera na reda s maksimalen broi simvoli (%d) e: %d\n\n", stats->maxLen, stats->maxLenNum);
}

/* po zadaden dataReader popylva statistikite za broq sreshtaniq na izbranite operatori i namira reda s maksimalen broi simvoli.
Obrabotvanata programa e jelatelno da e kompiliruema za da se izvedat pravilno rezultatite. Razpoznavat se komentari i simvolni nizove,
ogradeni s kavichki. Operatorite trqbva da otgovartqt na iziskvanita na ezika C - t.e. da imenata da sa s malki bukvi i da ne sa prekysnati po nikakyv nachin.
Razpoznavat se i blokovi konstrukcii, zapochvashti s { i zavyrshvashti s }. Parametyra lineNum ima kozmetichen efekt - posochva koi red se obrabotva
v momenta, currentPos pokazva koi simvol ot tekushtiq red se obrabotva */
char * ProccessExpression(char * currentPos, PEXPRESSION_STATS stats, int * lineNum, PEXPR_PROC_DATA dataReader) {
   int tokenLen = 0;
    int inDoStatement = false; /* pokazva dali sme v do/while blok */
   int endOfData = false;
   int inSingleComment = false; /* pokazva dali sme v komentar zapochvasht s // (ednoredov komentar) */
   int inMultiLineComment = false; /* pokazva dali sme v blokov komentar */
   int inQuotes = false; /* pokazva dali sme v konstanten string */

   while (1) {
      while (currentPos && *currentPos) {
         /* proverki za vsichki obrabotvani simvoli i operatori */
         if (!inQuotes && !inSingleComment && ! inMultiLineComment && *currentPos == '{') {
            stats->currentLineLen++;
            currentPos = ProccessExpression(currentPos + 1, stats, lineNum, dataReader);
         }
         else
         if (!inQuotes && !inSingleComment && ! inMultiLineComment && *currentPos == '}') {
            stats->currentLineLen++;
            return currentPos + 1;
         }
         else
         if (!inQuotes && !inSingleComment && ! inMultiLineComment && ContainsToken(currentPos, "do", &tokenLen)) {
            stats->currentLineLen += tokenLen;
            inDoStatement = true;
            currentPos += tokenLen;
            stats->doCount++;
         }
         else
         if (!inQuotes && !inSingleComment && ! inMultiLineComment && ContainsToken(currentPos, "while", &tokenLen)) {
            stats->currentLineLen += tokenLen;

            if (!inDoStatement)
               stats->whileCount++;

            inDoStatement = false;
            currentPos += tokenLen;
         }
         else
         if (!inQuotes && !inSingleComment && ! inMultiLineComment && ContainsToken(currentPos, "for", &tokenLen)) {
            stats->currentLineLen += tokenLen;
            currentPos += tokenLen;
            stats->forCount++;
         }
         else
         if (!inQuotes && !inSingleComment && ! inMultiLineComment && ContainsToken(currentPos, "//", &tokenLen)) {
            stats->currentLineLen += tokenLen;
            currentPos += tokenLen;
            inSingleComment = true;
         }
         else
         if (!inQuotes && !inSingleComment && ! inMultiLineComment && ContainsToken(currentPos, "/*", &tokenLen)) {
            stats->currentLineLen += tokenLen;
            currentPos += tokenLen;
            inMultiLineComment = true;
         }
         else
         if (!inQuotes && !inSingleComment && ContainsToken(currentPos, "*/", &tokenLen)) {
            stats->currentLineLen += tokenLen;
            currentPos += tokenLen;
            inMultiLineComment = false;
         }
         else
         if (!inSingleComment && !inMultiLineComment && *currentPos=='"') {
            stats->currentLineLen++;
            currentPos++;
            inQuotes = !inQuotes;
         }
         else {
            if (!inSingleComment && ! inMultiLineComment && *currentPos != ' ' && *currentPos > 27)
               stats->currentLineLen++;

            currentPos++;
         }

         if (currentPos)
            stats->currentLineLen += FlushInvalidChars(&currentPos);
      }

      /* obnovqvame informaciqta za masimalniq broi simvoli */
      if (stats->currentLineLen > stats->maxLen) {
         stats->maxLen = stats->currentLineLen;
         stats->maxLenNum = *lineNum;
      };

      /* obrabotkata na tekushtiq red e prikluchila - vzimame sledvashtiq */

      (*(dataReader->reader)) (dataReader, *lineNum, &endOfData);
      if (endOfData)
         break;

      stats->currentLineLen = 0;
      inSingleComment = false;
      currentPos = dataReader->buffer;

      (*lineNum)++;
   }

   return NULL;
}

/* izpolzva se za testvane na programata - zadava se programa, obhvashtashti kolkoto se moje poveche vyzmojnosti za greshki i se
sravnqva rezultata */
void SelfTest() {
   const char * testData[6] =    /* 2 validni do/while operatora, 1 while i 1 for */
   { "do { ",
   " while(1) { } // do do sdjkhf jdhfs while jhgfj gdsjfgdkjh",
   "} while(1) \"while\"",
    "for (int i = 0; i < 10; i++) ",
    " do { } while();",
   ""};

   EXPRESSION_STATS stats;
   EXPR_PROC_DATA reader;

   reader.dataSource = testData;
   reader.reader = ArrayReader;
   reader.buffer = (char *) malloc(256 * sizeof(char));
   reader.bufferSize = 256;
   reader.dataSourceSize = 6; /* ako se promenqt broq na redovete v testovata programa tova chislo trqbva da se obnovi */

   int lineNum = 0;
   InitStats(&stats);

   ProccessExpression(NULL, &stats, &lineNum, &reader);
   if (stats.doCount == 2 && stats.forCount == 1 && stats.whileCount == 1)
      printf("DONE\n");
   else {
      printf("FAILED!!!\n");
      WriteStats(&stats, stdout);
   }

   free(reader.buffer);
}

/* proverqva dali edno ime na fail ima razshirenie .C */
int ValidFileName(char * name) {
   int len;

   len = strlen(name);
   if (len < 3)
      return 0;

   if ((name[len-1] == 'C' || name[len-1] == 'c') && (name[len-2] == '.'))
      return 1;
   else
      return 0;
}

/* chete ime na fail ot klaviaturata i premahva simvolite za nov red (v rezultat na natiskaneto na Enter) */
int ReadFileName(char * message, char * buffer, int buffSize) {
   int res;
   printf("%s: ", message);
   res = fgets(buffer, buffSize, stdin) != NULL;

   while (buffer[strlen(buffer) - 1] == 13 || buffer[strlen(buffer) - 1] == 10)
      buffer[strlen(buffer) - 1] = 0;

   return res;
}

/*obrabotva 1-vata komanda ot menuto */
void MIFileToFile() {
   char fileName[255];
   FILE * in;
   FILE * out;
   EXPRESSION_STATS stats;
   EXPR_PROC_DATA reader;
   int lineNum = 0;

   printf("\n\nChetene ot file i zapis na rezultata\n\n");
   InitStats(&stats);

   /* chete imeto nja izhodniq fail */
   while (!ReadFileName("Ime na faila s danni", fileName, 255) || !ValidFileName(fileName))
      printf("Nekorektno ime. Opitaite pak!\n");

   in = fopen(fileName, "rt");

   reader.dataSource = in;
   reader.reader = StreamReader;
   reader.buffer = (char *) malloc(256 * sizeof(char));
   reader.bufferSize = 256;

   /* obrbotka */
   ProccessExpression(NULL, &stats, &lineNum, &reader);

   /* izvejdane na rezultata */
   while (!ReadFileName("Ime na faila za rezultata", fileName, 255))
      printf("Nekorektno ime. Opitaite pak!\n");

   out = fopen(fileName, "wt");
   WriteStats(&stats, out);

   printf("dannite sa zapisani v %s \n", fileName);

   /* izchistvane na zaetite resursi */
   free(reader.buffer);

   fclose(in);
   fclose(out);
}

/* obrabotva vtorata komanda ot menuto */
void MIFileToScr() {
   char fileName[255];
   FILE * in;
   EXPRESSION_STATS stats;
   EXPR_PROC_DATA reader;
   int lineNum = 0;

   printf("\n\nChetene ot file i izvejdane na rezultata\n\n");
   InitStats(&stats);

   while (!ReadFileName("Ime na faila s danni", fileName, 255) || !ValidFileName(fileName))
      printf("Nekorektno ime. Opitaite pak!\n");

   in = fopen(fileName, "rt");

   reader.dataSource = in;
   reader.reader = StreamReader;
   reader.buffer = (char *) malloc(256 * sizeof(char));
   reader.bufferSize = 256;

   ProccessExpression(NULL, &stats, &lineNum, &reader);

   printf("\n");
   WriteStats(&stats, stdout);

   free(reader.buffer);

   fclose(in);
}

/* obrabotva tretata komanda ot menuto */
void MIKbdToFile() {
   char fileName[255];
   FILE * out;
   EXPRESSION_STATS stats;
   EXPR_PROC_DATA reader;
   int lineNum = 0;

   printf("\n\nChetene ot klaviatura i zapis na rezultata\n\n");
   InitStats(&stats);

   printf("Vyvejdaneto e red po red kato za krai napishete END (trqbva da e edinstvenata duma na reda) \n");

   reader.reader = KeyboardReader;
   reader.buffer = (char *) malloc(256 * sizeof(char));
   reader.bufferSize = 256;

   ProccessExpression(NULL, &stats, &lineNum, &reader);

   while (!ReadFileName("Ime na faila za rezultata", fileName, 255))
      printf("Nekorektno ime. Opitaite pak!\n");

   out = fopen(fileName, "wt");
   WriteStats(&stats, out);

   printf("dannite sa zapisani v %s \n", fileName);

   free(reader.buffer);

   fclose(out);
}

/* obrabotva chetvyrtata komanda ot menuto */
void MIKbdToScr() {
   EXPRESSION_STATS stats;
   EXPR_PROC_DATA reader;
   int lineNum = 0;

   printf("\n\nChetene ot klaviatura i izvejdane na rezultata\n\n");
   InitStats(&stats);

   printf("Vyvejdaneto e red po red kato za krai napishete END (trqbva da e edinstvenata duma na reda) \n");

   reader.reader = KeyboardReader;
   reader.buffer = (char *) malloc(256 * sizeof(char));
   reader.bufferSize = 256;

   ProccessExpression(NULL, &stats, &lineNum, &reader);
   printf("\n");
   WriteStats(&stats, stdout);

   free(reader.buffer);
}

int main()
{
   int ans = 0;

   do
   {
      /* izvejdame menuto na programata */
      printf("MENU\n");
      printf("\t1. Vyvejdane ot fail i zapis na rezultata\n");
      printf("\t2. Vyvejdane ot fail i izvejdane na ekrana\n");
      printf("\t3. Vyvejdane ot klaviaturata i zapis vyv fail\n");
      printf("\t4. Vyvejdane ot klaviaturata i izvejdane na ekrana\n");
      printf("\t0. Izhod\n");
      printf("\n(0..4): ");

      if (scanf("%d", &ans) == 1)
      {
         fflush(stdin);

         switch (ans)
         {
         case 1 :
            MIFileToFile();

            break;
         case 2:
            MIFileToScr();

            break;
         case 3 :
            MIKbdToFile();

            break;
         case 4 :
            MIKbdToScr();

            break;
         }
      }
      else
         ans = -1;

      fflush(stdin);

      printf("\n");
   } while (ans);

   /* getch(); */ /* ako ekrana ne se zadyrja ot sredata da se razkomentira reda */

    return 0;
}
