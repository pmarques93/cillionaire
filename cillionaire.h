
#ifndef __cillionaire_h__
#define __cillionaire_h__

#define MSG_BYE "*** Sad to see you go..."
#define MSG_UNKNOWN ">*** Unknown option..."

void keyPress(char * file_name);
void printMenu(void);
void printCredits(void);
void printScore(char * aux_nome, int level, int joker_50_50);
#endif

