#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

   char easy[10] = {"easy"};
   char medium[10] = {"medium"};
   char hard[10] = {"hard"};

   FILE *in_file = fopen("quest", "r");


   if(medium[0]!= '\0')
   {
      printf("%s\n", medium);

      fclose(in_file);
   }

   else if(easy[0]!= '\0')
   {
      
      printf("%s\n", easy);

      fclose(in_file);
   }

   else if(hard[0]!= '\0')
   {
      printf("%s\n", hard);

      fclose(in_file);
   }


   return 0;
}