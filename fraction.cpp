#include <iostream>
#include <cstdio>

using namespace std;

class Fraction{
private:
    int a; int b; int c; int d;  int x; int y; int z;
    /* a,c는 분자 b,d는 분모, T는 testcase x,y,z는 정답 y는 남는 분자 z는 분모 */
public:
    void init(int a,int b,int c,int d)
    {
        this-> a = a;
        this-> b = b;
        this-> c = c;
        this-> d = d;

    }

    void gcd()
    {
        /* 1. 최대 공약수 구하기 */
        if(b == d){
            /* 그대로 놔두고 */
        }
        else if(b < d)
        {
          if(d % b == 0)
          {
              /*나눠지면 d를 b로 나눈 몫만큼 곱해준다 a분자에  */
              a = a*d/b;    /* 6/2 * a  */
              b = b*d/b;    /* 2 *2 */
          }
          else
          {
           /* 나눠지지 않을때는 서로 교차해서 곱해준다 a = a*d c = c*b */
            int tmp1 = b;
            int tmp2 = d;
            a = a * tmp2;
            c = c * tmp1;
            b = b * tmp2;
            d = d * tmp1;
          }
        }
        else if(b > d)
        {
          if(b % d == 0)
          {
            /*나눠지면 b를 d로 나눈 몫만큼 곱해준다 c분자에  */
              c = c*b/d;    /* 6/2 * c  */
              d = d*b/d;    /* d도 맞춰주기 */

          }
          else{
           /* 나눠지지 않을때는 서로 교차해서 곱해준다 a = a*d c = c*b */
            int tmp1 = b;
            int tmp2 = d;
            a = a * tmp2;
            c = c * tmp1;
            b = b * tmp2;
            d = d * tmp1;
          }

        }
    }

    void answer()
    {
        for(int i= 2; i <= 10000; i++)
        {
            while(1)
            {
              if(y%i == 0 && z%i == 0)
              {
                 y = y/i; /* 몫이 계속 저장됨 */
                 z = z/i;
              }
              else
              {
                  break;
              }
            }
        }

    }


    void solution(FILE* fp2){
        /* 만약 x가 0이고 y가 0보다 크면 y,z만 차례로 출력하라
        만약 y가 0이면 x만 출력하라  기본 원칙은 y < z 형태로 만든후 x,y,z 차례대로 출력 */
        gcd();
        z = b;

        /*x,y 구해야함 */

        if( (a + c) % z == 0 )
        {
            /* 분자가 분모로 완전히 나눠질때 x만 구하면 됨 */
            x = (a + c)/z;
            fprintf(fp2,"%d\n",x);

        }
        else{
            /* 분자가 분모로 나눠지지 않을때 2가지 경우가 있음 분자가 분모보다 작거나 분자가 분모보다 크거나 */
            if( a + c < z)
            {
                x = 0;
                y = a+c;
                answer();
                fprintf(fp2, "%d %d\n",y,z);

            }
            else if( a + c > z)
            {
                /* 몫은 x고 나머지가 y */
                x = (a + c)/z;
                y = (a + c)%z;
                answer();
                fprintf(fp2, "%d %d %d\n",x,y,z);

            }
        }

    }


};





int main()
{
    FILE* fp1 = fopen("fraction.inp","r");
    FILE* fp2 = fopen("fraction.out","w");
    /*파일 입출력 인풋 아웃풋 설정 */

    int a; int b; int c; int d; int T; int x; int y; int z;
    /* a,c는 분자 b,d는 분모, T는 testcase x,y,z는 정답 y는 남는 분자 z는 분모  */

    fscanf(fp1, "%d",&T);
    /*testcase 입력 */
    Fraction frc;

    while(T--)
    {
        fscanf(fp1,"%d %d %d %d", &a,&b,&c,&d);
        frc.init(a,b,c,d);
        frc.solution(fp2);
    }


    return 0;
}
