#include <stdio.h>
#include "hash.h"

int recurse1(uint64_t hashedID);
int recurse2(uint64_t hashedID);
int recurse3(uint64_t hashedID);
int recurse4(uint64_t hashedID);
int recurse5(uint64_t hashedID);
int recurse6(uint64_t hashedID);

int recurse1(uint64_t hashedID){
  if(hashedID % 67 == 0){
    return 0;
  }
  return 1 + recurse2(hashedID - 1);
}

int recurse2(uint64_t hashedID){
  if(hashedID % 67 == 0){
    return 0;
  }
  return 1 + recurse3(hashedID - 1);
}

int recurse3(uint64_t hashedID){
  if(hashedID % 67 == 0){
    return 0;
  }
  return 1 + recurse4(hashedID - 1);
}

int recurse4(uint64_t hashedID){
  if(hashedID % 67 == 0){
    return 0;
  }
  return 1 + recurse1(hashedID - 1);
}

int recurse5(uint64_t hashedID){
  if(hashedID % 29 == 0){
    return 0;
  }
  return 1 + recurse6(hashedID - 1);
}

int recurse6(uint64_t hashedID){
  if(hashedID % 29 == 0){
    return 0;
  }
  return 1 + recurse5(hashedID - 1);
}

void add100(uint64_t hashedID){
  for(int i = 0; i < 100; i++){
    hashedID += 1;
  }
}

void subtract100(uint64_t hashedID){
  for(int i = 0; i < 100; i++){
    hashedID -= 1;
  }
}

int main(int argc, char* argv[]){
  if (argc != 2) {
    printf("Please include your PSU email ID as a command line argument! i.e., ./gdb-practice abc1234 (or within gdb, r abc1234)\n");
    return 1;
  }

  uint64_t hashedID1 = hash1(argv[1]);
  recurse1(hashedID1);
  add100(hashedID1);
  subtract100(hashedID1);
  
  uint64_t hashedID2 = hash2(argv[1]);
  recurse1(hashedID2);
  add100(hashedID2);
  subtract100(hashedID2);
  
  return 0;
}
