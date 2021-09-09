#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


signed short add(signed short x,signed short y);
signed short read(signed short x);
signed short mov(signed short x, signed short y);
signed short sub(signed short x,signed short y);
signed short mul(signed short x,signed short y);
signed short divt(signed short x,signed short y);
char * trim_space(char *str);
int jump(int argumentType, signed short x, signed short y);

signed short ax=0;
signed short bx=0;
signed short cx=0;
signed short dx=0;
int main(int argc, char* argv[])
{
  char line[100][50];
    FILE *Fp = NULL;
    int i = 0;
    int total = 0;

    Fp = fopen(argv[1], "r");
                                                                                                          
    while(fgets(line[i],sizeof(line[i]),Fp) != NULL) {
        i++;
    }
    
    total = i;

     int lineCount = 0;
    while(lineCount != total){

      if(strcmp(line[lineCount],"\n")==0){
        lineCount++;
        continue;
      }
      else{
          char *temp;
          char token1[100000];
          char *token;
          temp = line[lineCount];

          strcpy(token1,temp);

         token = strtok(token1," ");
      if(strcmp(token, "read") == 0){
        token = strtok(NULL," ");
        token = trim_space(token);

    if(strcmp(token,"ax")==0){
          ax = read(ax);                                                                                                          
          }
        else if(strcmp(token,"bx")==0){
          bx = read(bx);                                                                                                       
            }
        else if(strcmp(token,"cx")==0){
          cx = read(cx);                                                                                                              
            }
        else if(strcmp(token,"dx")==0){
          dx = read(dx);                                                                                                                        
          }                                                                                                                            
         lineCount++;
        }
      else if(strcmp(token, "mov") == 0){
        //mov file                                                                                                                                     
        char *firstArg;
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
           if(strcmp(secondArg,"ax")==0){
              if(strcmp(firstArg,"ax")==0){
                ax = mov(ax,ax);
              }
              else if(strcmp(firstArg,"bx")==0){
                ax = mov(bx,ax);
              }
              else if(strcmp(firstArg,"cx")==0){
                ax = mov(cx,ax);
            }
              else if(strcmp(firstArg,"dx")==0){
                ax = mov(dx,ax);
              }
              else{
                signed short num = atoi(firstArg);
                ax = mov(num,ax);
              }

           }
           else if(strcmp(secondArg,"bx")==0){
              if(strcmp(firstArg,"ax")==0){
                bx = mov(ax,bx);
              }
              else if(strcmp(firstArg,"bx")==0){
                bx = mov(bx,bx);
              }
              else if(strcmp(firstArg,"cx")==0){
                bx = mov(cx,bx);
            }
              else if(strcmp(firstArg,"dx")==0){
                bx = mov(dx,bx);
              }
              else{
                signed short num = atoi(firstArg);
                bx = mov(num,bx);
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(firstArg,"ax")==0){
                cx = mov(ax,cx);
              }
              else if(strcmp(firstArg,"bx")==0){
                cx = mov(bx,cx);
              }
              else if(strcmp(firstArg,"cx")==0){
                cx = mov(cx,cx);
            }
              else if(strcmp(firstArg,"dx")==0){
                cx = mov(dx,cx);
              }
              else{
                signed short num = atoi(firstArg);

                cx = mov(num,cx);

              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(firstArg,"ax")==0){
                dx = mov(ax,dx);
              }
              else if(strcmp(firstArg,"bx")==0){
                dx = mov(bx,dx);
              }
              else if(strcmp(firstArg,"cx")==0){
                dx = mov(cx,dx);
            }
              else if(strcmp(firstArg,"dx")==0){
                dx = mov(dx,dx);
              }
              else{
                signed short num = atoi(firstArg);
                dx = mov(num,dx);
              }
        }
        
        lineCount++;
      }
       else if(strcmp(token, "print") == 0){
        token = strtok(NULL," ");
        token = trim_space(token);
        if(strcmp(token,"ax")==0){
          printf("%hi",ax);
          }
        else if(strcmp(token,"bx")==0){
          printf("%hi",bx);
            }
        else if(strcmp(token,"cx")==0){
          printf("%hi",cx);
            }
        else if(strcmp(token,"dx")==0){
          printf("%hi",dx);
          }
        else{
          signed short num = atoi(token);
          printf("%hi",num);
        }
        lineCount++;
}
       else if(strcmp(token, "add") == 0){
        char *firstArg;
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
        if(atoi(firstArg)==0){
           if(strcmp(secondArg,"ax")==0){
              if(strcmp(firstArg,"ax")==0){
                ax = add(ax,ax);
              }
              else if(strcmp(firstArg,"bx")==0){
                ax = add(bx,ax);
              }
              else if(strcmp(firstArg,"cx")==0){
                ax = add(cx,ax);
            }
              else if(strcmp(firstArg,"dx")==0){
                ax = add(dx,ax);
              }
           }
        else if(strcmp(secondArg,"bx")==0){
             if(strcmp(firstArg,"ax")==0){
                bx = add(ax,bx);
              }
              else if(strcmp(firstArg,"bx")==0){
                bx = add(bx,bx);
              }
              else if(strcmp(firstArg,"cx")==0){
                bx = add(cx,bx);
            }
              else if(strcmp(firstArg,"dx")==0){
                bx = add(dx,bx);
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(firstArg,"ax")==0){
                cx = add(ax,cx);
              }
              else if(strcmp(firstArg,"bx")==0){
                cx = add(bx,cx);
                }
              else if(strcmp(firstArg,"cx")==0){
                cx = add(cx,cx);
                }
              else if(strcmp(firstArg,"dx")==0){
                cx = add(dx,cx);
              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(firstArg,"ax")==0){
                dx = add(ax,dx);
              }
              else if(strcmp(firstArg,"bx")==0){
                dx = add(bx,dx);
              }
              else if(strcmp(firstArg,"cx")==0){
                dx = add(cx,dx);
            }
              else if(strcmp(firstArg,"dx")==0){
                dx = add(dx,dx);
              }
        }
        }
        else{
         signed short num = atoi(firstArg);
           if(strcmp(secondArg,"ax")==0){
                ax = add(num,ax);
              }
              else if(strcmp(secondArg,"bx")==0){
                bx = add(num,ax);
              }
              else if(strcmp(secondArg,"cx")==0){
                cx = add(num,ax);
            }
              else if(strcmp(secondArg,"dx")==0){
                dx = add(num,ax);
              }
        }
         lineCount++;
      }
       else if(strcmp(token, "sub") == 0){
        char *firstArg;
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
        if(atoi(firstArg)==0){
           if(strcmp(secondArg,"ax")==0){
              if(strcmp(firstArg,"ax")==0){
                ax = sub(ax,ax);
              }
              else if(strcmp(firstArg,"bx")==0){
                ax = sub(bx,ax);
              }
              else if(strcmp(firstArg,"cx")==0){
                ax = sub(cx,ax);
            }
              else if(strcmp(firstArg,"dx")==0){
                ax = sub(dx,ax);
              }

           }
        else if(strcmp(secondArg,"bx")==0){
             if(strcmp(firstArg,"ax")==0){
                bx = sub(ax,bx);
              }
              else if(strcmp(firstArg,"bx")==0){
                bx = sub(bx,bx);
              }
              else if(strcmp(firstArg,"cx")==0){
                bx = sub(cx,bx);
            }
              else if(strcmp(firstArg,"dx")==0){
                bx = sub(dx,bx);
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(firstArg,"ax")==0){
                cx = sub(ax,cx);
              }
              else if(strcmp(firstArg,"bx")==0){
                cx = sub(bx,cx);
                }
              else if(strcmp(firstArg,"cx")==0){
                cx = sub(cx,cx);
                }
              else if(strcmp(firstArg,"dx")==0){
                cx = sub(dx,cx);
              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(firstArg,"ax")==0){
                dx = sub(ax,dx);
              }
              else if(strcmp(firstArg,"bx")==0){
                dx = sub(bx,dx);
              }
              else if(strcmp(firstArg,"cx")==0){
                dx = sub(cx,dx);
            }
              else if(strcmp(firstArg,"dx")==0){
                dx = sub(dx,dx);
              }
        }
        }
        else{
         signed short num = atoi(firstArg);
           if(strcmp(secondArg,"ax")==0){
                ax = sub(num,ax);
              }
              else if(strcmp(secondArg,"bx")==0){
                bx = sub(num,ax);
              }
              else if(strcmp(secondArg,"cx")==0){
                cx = sub(num,ax);
            }
              else if(strcmp(secondArg,"dx")==0){
                dx = sub(num,ax);
              }
        }
         lineCount++;
      }
       else if(strcmp(token, "mul") == 0){
        char *firstArg;
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
        if(atoi(firstArg)==0){
           if(strcmp(secondArg,"ax")==0){
              if(strcmp(firstArg,"ax")==0){
                ax = mul(ax,ax);
              }
              else if(strcmp(firstArg,"bx")==0){
                ax = mul(bx,ax);
              }
              else if(strcmp(firstArg,"cx")==0){
                ax = mul(cx,ax);
            }
              else if(strcmp(firstArg,"dx")==0){
                ax = mul(dx,ax);
              }

           }
        else if(strcmp(secondArg,"bx")==0){
             if(strcmp(firstArg,"ax")==0){
                bx = mul(ax,bx);
              }
              else if(strcmp(firstArg,"bx")==0){
                bx = mul(bx,bx);
              }
              else if(strcmp(firstArg,"cx")==0){
                bx = mul(cx,bx);
            }
              else if(strcmp(firstArg,"dx")==0){
                bx = mul(dx,bx);
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(firstArg,"ax")==0){
                cx = mul(ax,cx);
              }
              else if(strcmp(firstArg,"bx")==0){
                cx = mul(bx,cx);
                }
              else if(strcmp(firstArg,"cx")==0){
                cx = mul(cx,cx);
                }
              else if(strcmp(firstArg,"dx")==0){
                cx = mul(dx,cx);
              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(firstArg,"ax")==0){
                dx = mul(ax,dx);
              }
              else if(strcmp(firstArg,"bx")==0){
                dx = mul(bx,dx);
              }
              else if(strcmp(firstArg,"cx")==0){
                dx = mul(cx,dx);
            }
              else if(strcmp(firstArg,"dx")==0){
                dx = mul(dx,dx);
              }
        }
        }
        else{
         signed short num = atoi(firstArg);
         
          if(strcmp(secondArg,"ax")==0){
                ax = mul(num,ax);
              }
              else if(strcmp(secondArg,"bx")==0){
                bx = mul(num,bx);
              }
              else if(strcmp(secondArg,"cx")==0){
                cx = mul(num,cx);
            }
              else if(strcmp(secondArg,"dx")==0){
                dx = mul(num,dx);
              }
        }
         lineCount++;
      }
       else if(strcmp(token, "div") == 0){
        char *firstArg;
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
        if(atoi(firstArg)==0){
           if(strcmp(secondArg,"ax")==0){
              if(strcmp(firstArg,"ax")==0){
                ax = divt(ax,ax);
              }
              else if(strcmp(firstArg,"bx")==0){
                ax = divt(bx,ax);
              }
              else if(strcmp(firstArg,"cx")==0){
                ax = divt(cx,ax);
            }
              else if(strcmp(firstArg,"dx")==0){
                ax = divt(dx,ax);
              }

           }
        else if(strcmp(secondArg,"bx")==0){
             if(strcmp(firstArg,"ax")==0){
                bx = divt(ax,bx);
              }
              else if(strcmp(firstArg,"bx")==0){
                bx = divt(bx,bx);
              }
              else if(strcmp(firstArg,"cx")==0){
                bx = divt(cx,bx);
            }
              else if(strcmp(firstArg,"dx")==0){
                bx = divt(dx,bx);
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(firstArg,"ax")==0){
                cx = divt(ax,cx);
              }
              else if(strcmp(firstArg,"bx")==0){
                cx = divt(bx,cx);
                }
              else if(strcmp(firstArg,"cx")==0){
                cx = divt(cx,cx);
                }
              else if(strcmp(firstArg,"dx")==0){
                cx = divt(dx,cx);
              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(firstArg,"ax")==0){
                dx = divt(ax,dx);
              }
              else if(strcmp(firstArg,"bx")==0){
                dx = divt(bx,dx);
              }
              else if(strcmp(firstArg,"cx")==0){
                dx = divt(cx,dx);
            }
              else if(strcmp(firstArg,"dx")==0){
                dx = divt(dx,dx);
              }
        }
        }
        else{
         signed short num = atoi(firstArg);
           if(strcmp(secondArg,"ax")==0){
                ax = divt(num,ax);
              }
              else if(strcmp(secondArg,"bx")==0){
                bx = divt(num,ax);
              }
              else if(strcmp(secondArg,"cx")==0){
                cx = divt(num,ax);
            }
              else if(strcmp(secondArg,"dx")==0){
                dx = divt(num,ax);
              }
        }
         lineCount++;
      }
       else if(strcmp(token, "jmp") == 0){
         char *firstArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
         int num = atoi(firstArg);
         lineCount=num;
      }
       else if(strcmp(token, "je") == 0){
        char *firstArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        int num = atoi(firstArg);
  //*******************************
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
  //*******************************
        char *thirdArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        thirdArg = token;
        int argType =0;
      //first case - both values are numbers  ******************************************************************************************
      if(atoi(secondArg) != 0 && atoi(thirdArg) !=0){
        //number can be converted to int
        int secondNum = atoi(secondArg);
        int thirdNum = atoi(thirdArg);
        int boolNum = jump(argType,secondNum,thirdNum);
        if(boolNum == 0){
          lineCount = num;
        }
        else{
          lineCount++;
        }

      }
      //second case - secondarg is a number and third arg is a register
      else if(atoi(secondArg) != 0 && atoi(thirdArg) == 0){
        //lineCount++;
        
        if(strcmp(thirdArg,"ax")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,ax);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"bx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,bx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"cx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,cx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"dx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,dx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
          //Third case- thirdarg is a number and secondarg is a register
          else if(atoi(secondArg) == 0 && atoi(thirdArg) != 0){
        //lineCount++;
        if(strcmp(secondArg,"ax")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,ax,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"bx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,bx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"cx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,cx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"dx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,dx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
        //case four - both are registers
        else if(atoi(secondArg) == 0 && atoi(thirdArg) == 0){
          if(strcmp(secondArg,"ax")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

           }
        else if(strcmp(secondArg,"bx")==0){
             if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
        }
       }
       }
       else if(strcmp(token, "jne") == 0){
        char *firstArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        int num = atoi(firstArg);
  //*******************************
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
  //*******************************
        char *thirdArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        thirdArg = token;
        int argType =1;
      //first case - both values are numbers  ******************************************************************************************
      if(atoi(secondArg) != 0 && atoi(thirdArg) !=0){
        //number can be converted to int
        int secondNum = atoi(secondArg);
        int thirdNum = atoi(thirdArg);
        int boolNum = jump(argType,secondNum,thirdNum);
        if(boolNum == 0){
          lineCount = num;
        }
        else{
          lineCount++;
        }

      }
      //second case - secondarg is a number and third arg is a register
      else if(atoi(secondArg) != 0 && atoi(thirdArg) == 0){
        //lineCount++;
        
        if(strcmp(thirdArg,"ax")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,ax);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"bx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,bx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"cx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,cx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"dx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,dx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
          //Third case- thirdarg is a number and secondarg is a register
          else if(atoi(secondArg) == 0 && atoi(thirdArg) != 0){
        //lineCount++;
        if(strcmp(secondArg,"ax")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,ax,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"bx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,bx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"cx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,cx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"dx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,dx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
        //case four - both are registers
        else if(atoi(secondArg) == 0 && atoi(thirdArg) == 0){
          if(strcmp(secondArg,"ax")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

           }
        else if(strcmp(secondArg,"bx")==0){
             if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
        }
       }
       }
       else if(strcmp(token, "jg") == 0){
        char *firstArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        int num = atoi(firstArg);
  //*******************************
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
  //*******************************
        char *thirdArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        thirdArg = token;
        int argType =2;
      //first case - both values are numbers  ******************************************************************************************
      if(atoi(secondArg) != 0 && atoi(thirdArg) !=0){
        //number can be converted to int
        int secondNum = atoi(secondArg);
        int thirdNum = atoi(thirdArg);
        int boolNum = jump(argType,secondNum,thirdNum);
        if(boolNum == 0){
          lineCount = num;
        }
        else{
          lineCount++;
        }

      }
      //second case - secondarg is a number and third arg is a register
      else if(atoi(secondArg) != 0 && atoi(thirdArg) == 0){
        //lineCount++;
        
        if(strcmp(thirdArg,"ax")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,ax);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"bx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,bx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"cx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,cx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"dx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,dx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
          //Third case- thirdarg is a number and secondarg is a register
          else if(atoi(secondArg) == 0 && atoi(thirdArg) != 0){
        //lineCount++;
        if(strcmp(secondArg,"ax")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,ax,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"bx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,bx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"cx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,cx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"dx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,dx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
        //case four - both are registers
        else if(atoi(secondArg) == 0 && atoi(thirdArg) == 0){
          if(strcmp(secondArg,"ax")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,ax,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,ax,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,ax,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

           }
        else if(strcmp(secondArg,"bx")==0){
             if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,bx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,bx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,bx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,cx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,cx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,cx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,dx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,dx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,dx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
        }
       }
       }
       else if(strcmp(token, "jge") == 0){
        char *firstArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        int num = atoi(firstArg);
  //*******************************
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
  //*******************************
        char *thirdArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        thirdArg = token;
        int argType =3;
      //first case - both values are numbers  ******************************************************************************************
      if(atoi(secondArg) != 0 && atoi(thirdArg) !=0){
        //number can be converted to int
        int secondNum = atoi(secondArg);
        int thirdNum = atoi(thirdArg);
        int boolNum = jump(argType,secondNum,thirdNum);
        if(boolNum == 0){
          lineCount = num;
        }
        else{
          lineCount++;
        }

      }
      //second case - secondarg is a number and third arg is a register
      else if(atoi(secondArg) != 0 && atoi(thirdArg) == 0){
        //lineCount++;
        
        if(strcmp(thirdArg,"ax")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,ax);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"bx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,bx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"cx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,cx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"dx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,dx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
          //Third case- thirdarg is a number and secondarg is a register
          else if(atoi(secondArg) == 0 && atoi(thirdArg) != 0){
        //lineCount++;
        if(strcmp(secondArg,"ax")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,ax,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"bx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,bx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"cx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,cx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"dx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,dx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
        //case four - both are registers
        else if(atoi(secondArg) == 0 && atoi(thirdArg) == 0){
          if(strcmp(secondArg,"ax")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,ax,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,ax,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,ax,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

           }
        else if(strcmp(secondArg,"bx")==0){
             if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,bx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,bx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,bx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,cx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,cx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,cx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,dx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,dx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,dx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
        }
       }
       }
       else if(strcmp(token, "jl") == 0){
        char *firstArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        int num = atoi(firstArg);
  //*******************************
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
  //*******************************
        char *thirdArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        thirdArg = token;
        int argType = 4;
      //first case - both values are numbers  ******************************************************************************************
      if(atoi(secondArg) != 0 && atoi(thirdArg) !=0){
        //number can be converted to int
        int secondNum = atoi(secondArg);
        int thirdNum = atoi(thirdArg);
        int boolNum = jump(argType,secondNum,thirdNum);
        if(boolNum == 0){
          lineCount = num;
        }
        else{
          lineCount++;
        }

      }
      //second case - secondarg is a number and third arg is a register
      else if(atoi(secondArg) != 0 && atoi(thirdArg) == 0){
        //lineCount++;
        
        if(strcmp(thirdArg,"ax")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,ax);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"bx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,bx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"cx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,cx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"dx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,dx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
          //Third case- thirdarg is a number and secondarg is a register
          else if(atoi(secondArg) == 0 && atoi(thirdArg) != 0){
        //lineCount++;
        if(strcmp(secondArg,"ax")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,ax,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"bx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,bx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"cx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,cx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"dx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,dx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
        //case four - both are registers
        else if(atoi(secondArg) == 0 && atoi(thirdArg) == 0){
          if(strcmp(secondArg,"ax")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,ax,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,ax,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,ax,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

           }
        else if(strcmp(secondArg,"bx")==0){
             if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,bx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,bx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,bx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,cx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,cx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,cx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,dx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,dx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,dx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
        }
       }
       }
       else if(strcmp(token, "jle") == 0){
        char *firstArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        firstArg = token;
        int num = atoi(firstArg);
  //*******************************
        char *secondArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        secondArg = token;
  //*******************************
        char *thirdArg;
        token = strtok(NULL," ");
        token = trim_space(token);
        thirdArg = token;
        int argType = 5;
      //first case - both values are numbers  ******************************************************************************************
      if(atoi(secondArg) != 0 && atoi(thirdArg) !=0){
        //number can be converted to int
        int secondNum = atoi(secondArg);
        int thirdNum = atoi(thirdArg);
        int boolNum = jump(argType,secondNum,thirdNum);
        if(boolNum != -1){
          lineCount = num;
        }
        else if(boolNum == -1){
          lineCount++;
        }

      }
      //second case - secondarg is a number and third arg is a register
      else if(atoi(secondArg) != 0 && atoi(thirdArg) == 0){
        //lineCount++;
        
        if(strcmp(thirdArg,"ax")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,ax);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"bx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,bx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"cx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,cx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(thirdArg,"dx")==0){
          int secondNum = atoi(secondArg);
          int boolNum = jump(argType,secondNum,dx);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
          //Third case- thirdarg is a number and secondarg is a register
          else if(atoi(secondArg) == 0 && atoi(thirdArg) != 0){
        //lineCount++;
        if(strcmp(secondArg,"ax")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,ax,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"bx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,bx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"cx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,cx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
        else if(strcmp(secondArg,"dx")==0){
          int secondNum = atoi(thirdArg);
          int boolNum = jump(argType,dx,secondNum);
           if(boolNum != -1){
          lineCount = num;
        }
          else if(boolNum == -1){
            lineCount++;
          }
        }
          }
        //case four - both are registers
        else if(atoi(secondArg) == 0 && atoi(thirdArg) == 0){
          if(strcmp(secondArg,"ax")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,ax,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,ax,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,ax,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,ax,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

           }
        else if(strcmp(secondArg,"bx")==0){
             if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,bx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,bx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,bx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,bx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"cx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,cx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,cx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,cx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
                }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,cx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }

            }
           else if(strcmp(secondArg,"dx")==0){
              if(strcmp(thirdArg,"ax")==0){
                int boolNum = jump(argType,dx,ax);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"bx")==0){
                int boolNum = jump(argType,dx,bx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
              else if(strcmp(thirdArg,"cx")==0){
                int boolNum = jump(argType,dx,cx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
            }
              else if(strcmp(thirdArg,"dx")==0){
                int boolNum = jump(argType,dx,dx);
                if(boolNum != -1){
                  lineCount = num;
                }
                  else if(boolNum == -1){
                    lineCount++;
                  }
              }
        }
       }
       }    
       else{
         lineCount++;
       }                                                                                                         
      }
    }
    printf("\n");
    return 0;
}

signed short read(signed short x){
   scanf("%hi",&x);
   return x;
}

signed short mov(signed short x, signed short y){
  signed short temp;
  temp = x;
  y=temp;
  return y;
}

signed short add(signed short x,signed short y){
  y = x + y;
  return y;
}

signed short sub(signed short x,signed short y){
  y = y - x;
  return y;
}

signed short mul(signed short x,signed short y){
  y = x * y;
  return y;
}

signed short divt(signed short x,signed short y){
  y = x / y;
  return y;
}

char * trim_space(char *str) {
    char *end;
    /* skip leading whitespace */
    while (isspace(*str)) {
        str = str + 1;
    }
    /* remove trailing whitespace */
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end = end - 1;
    }
    /* write null character */
    *(end+1) = '\0';
    return str;
}

int jump(int argumentType, signed short x, signed short y){
//function that takes in the argument je,jne,jg,jge,jl,jle and returns true or false if it meets requirments
int boolNum = 0;
if(argumentType == 0){
  if(x == y){
    boolNum = 0;
  }
  else{
    boolNum = -1;
  }
}
else if(argumentType == 1){
  if(x != y){
    boolNum = 0;
  }
  else{
    boolNum = -1;
  }
}
else if(argumentType == 2){
  if(x > y){
    boolNum = 0;
  }
  else{
    boolNum = -1;
  }
}
else if(argumentType == 3){
  if(x >= y){
    boolNum = 0;
  }
  else{
    boolNum = -1;
  }
}
else if(argumentType == 4){
  if(x < y){
    boolNum = 0;
  }
  else{
    boolNum = -1;
  }
}
else if(argumentType == 5){
  if(x <= y){
    boolNum = 0;
  }
  else{
    boolNum = -1;
  }
}
return boolNum;
}