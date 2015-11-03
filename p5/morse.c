// Kelvin Ton
#include <stdio.h>
#include <ctype.h>
#define DONE 0
#define READ 1
#define WRITE 2

void get_choice(int *choice);
void read();
void write();

const char *codes[26] =
{
  ".-", "-...", "-.-.", "-..", ".", "..-.",
  "--.", "....", "..", ".---", "-.-", ".-..", "--",
  "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--.."
}; // morse code!

int main()
{
  int choice;

  do
  {
    get_choice(&choice);

    switch(choice)
    {
      case DONE: break;
      case READ: read(); break;
      case WRITE: write(); break;
      default : break;
    }

  } while (choice != DONE);

  return 0;
} // main()

void get_choice(int *choice)
{
  do
  {
    printf("Morse Menu\n"
    "0. Done.\n"
    "1. Read Morse code.\n"
    "2. Write Morse code.\n"
    "\n"
    "Your choice: ");
    scanf("%d", choice);

    if (*choice < DONE || *choice > WRITE)
    {
      printf("That is not between 0 and 2.\n"
        "Please try again.\n\n");
    } // endif

  } while (*choice < DONE && *choice > WRITE);
} // get_choice()

void write()
{
  printf("English message: ");
  char letter, newline;
  scanf("%c", &newline); // gets rid of the \n from menu
  
  do
  {
    scanf("%c", &letter);
    
    if (isalpha(letter))
    {
      letter = toupper(letter);
      int index = letter - 'A';
      int i = 0;
      
      do // loop through and print out one-by-one
      { // pretty sure printf(codes[index]) would work, too
        printf("%c", codes[index][i]);
        i++;
      } while (codes[index][i] != '\0'); // sentinel value
      
      printf(" "); // spacing between letters
    } // endif isalpha
    else // not alpha
    {
      if (letter == ' ') // two spaces in morse = one space in alpha
        printf(" "); // but not the other way around
      else // not a known character
        if (letter != '\n') // ignore newlines
          printf("?");
    } // endelse notalpha
    
  } while (letter != '\n');
  
  printf("\n");
} // write()

void read()
{
  printf("Morse code: ");
  char letter, letter_array[5]; // maxlen = 5
  
  char newline;
  scanf("%c", &newline);

  int index = 0; // initialize index
  
  do
  {
    
    scanf("%c", &letter);
    
    if (letter == '.' || letter == '-')
    {
      letter_array[index] = letter;
      index++;
    } // endif
    else //not dots or dash? evaluate
    {
      int j;
      
      if (index > 0) // if at least one valid character long
      {
        int matched = 0;
        
        for (j = 0; j < 26; j++) // begin A-Z loop
        {
          int k = 0, match = 1;
          
          do
          {
            if (letter_array[k] != codes[j][k])
              match = 0;
            k++;
          } while (k < index); // loop through morse code
          
          if (match == 1 && codes[j][k] == '\0') // match
          {
            printf("%c",j + 65); // print out letter
            matched = 1;
          } // end if
          
        } // endfor A-Z loop
        
        if (!matched)
          printf("?"); // no morse code match
          
      } // endif onechar+
      
      if (index == 0) // invalid character
      {
        if (letter == ' ') // if space, print
          printf(" ");
        if (letter != '\n' && letter != ' ')
          printf("?"); // otherwise, nope!
      } // endif
      
      index = 0; // reset index
    } // end else not dots/dash

  } while (letter != '\n');
  
  printf("\n");

} // read()