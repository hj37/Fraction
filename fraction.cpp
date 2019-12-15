#include <iostream>
#include <cstdio>

using namespace std;

class Fraction{
private:
    int a; int b; int c; int d;  int x; int y; int z;
    /* a,c�� ���� b,d�� �и�, T�� testcase x,y,z�� ���� y�� ���� ���� z�� �и� */
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
        /* 1. �ִ� ����� ���ϱ� */
        if(b == d){
            /* �״�� ���ΰ� */
        }
        else if(b < d)
        {
          if(d % b == 0)
          {
              /*�������� d�� b�� ���� ��ŭ �����ش� a���ڿ�  */
              a = a*d/b;    /* 6/2 * a  */
              b = b*d/b;    /* 2 *2 */
          }
          else
          {
           /* �������� �������� ���� �����ؼ� �����ش� a = a*d c = c*b */
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
            /*�������� b�� d�� ���� ��ŭ �����ش� c���ڿ�  */
              c = c*b/d;    /* 6/2 * c  */
              d = d*b/d;    /* d�� �����ֱ� */

          }
          else{
           /* �������� �������� ���� �����ؼ� �����ش� a = a*d c = c*b */
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
                 y = y/i; /* ���� ��� ����� */
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
        /* ���� x�� 0�̰� y�� 0���� ũ�� y,z�� ���ʷ� ����϶�
        ���� y�� 0�̸� x�� ����϶�  �⺻ ��Ģ�� y < z ���·� ������ x,y,z ���ʴ�� ��� */
        gcd();
        z = b;

        /*x,y ���ؾ��� */

        if( (a + c) % z == 0 )
        {
            /* ���ڰ� �и�� ������ �������� x�� ���ϸ� �� */
            x = (a + c)/z;
            fprintf(fp2,"%d\n",x);

        }
        else{
            /* ���ڰ� �и�� �������� ������ 2���� ��찡 ���� ���ڰ� �и𺸴� �۰ų� ���ڰ� �и𺸴� ũ�ų� */
            if( a + c < z)
            {
                x = 0;
                y = a+c;
                answer();
                fprintf(fp2, "%d %d\n",y,z);

            }
            else if( a + c > z)
            {
                /* ���� x�� �������� y */
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
    /*���� ����� ��ǲ �ƿ�ǲ ���� */

    int a; int b; int c; int d; int T; int x; int y; int z;
    /* a,c�� ���� b,d�� �и�, T�� testcase x,y,z�� ���� y�� ���� ���� z�� �и�  */

    fscanf(fp1, "%d",&T);
    /*testcase �Է� */
    Fraction frc;

    while(T--)
    {
        fscanf(fp1,"%d %d %d %d", &a,&b,&c,&d);
        frc.init(a,b,c,d);
        frc.solution(fp2);
    }


    return 0;
}
