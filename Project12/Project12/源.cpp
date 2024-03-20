#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <windows.h>
#define N 6      //���嶥�㼯�ϸ��������Ը�����Ҫ���ġ� 
#define Max_num N*N
#define inf 99     //inf����Ϊ����󣬿��Ը���ֵ 

int  s[N] = { 0 }, G[N][N] = { 0 }; //s���·�������Ķ��㼯�ϣ�GΪͼ�ڽӾ��� 
static char u[N] = { '0' };    //����v�ļ���ȫ��u 

int main() {
    int i, j, vs, vd;
    char start, end;
    void dijkstra(int vs, int vd);   //vs��Ӧstart��vd��Ӧend 
    void input_graph(int a[N][N]); //��������ͼ��ϵ 
    void display_matrix(int a[N][N]); //��ʾ����ͼ�ڽ���� 
    void copyright();
    copyright();
    //��ʼ��ͼG���Խ���Ϊ0������Ϊ�����inf  
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (i != j)
                G[i][j] = inf;

    //���벢��ʾG�ľ���
    input_graph(G);  display_matrix(G);
    putchar(getchar());
    // ���������յ�start,end 
    printf("\n�����������յ�(���߿ո�������س���������ʽΪa d��0 3��)��\n");
    scanf("%c %c", &start, &end);
    printf("\n�����������յ�start-->endΪ��%c-->%c��", start, end);
    //�ҵ������ص��ڱ�����������λ����a��Ӧ0��b��Ӧ1 
    for (j = 0; j < N; j++) {
        if (start == u[j]) vs = j; //ɨ�輯��A���Ա��ҵ��ڶ�ά������λ��i,j 
        if (end == u[j])   vd = j; //��start=a,end=d,���ҵ�i=0,j=3,�Ӷ�a[0][1]=1 
    }
    printf("������%d�Ž�㣨vs��-->��%d�Ž�㣨vd��\n", vs, vd);

    dijkstra(vs, vd);    //����ĺ��Ĳ��� 

    printf("\n");
    system("pause");
    printf("ѧ�� :202205280140 ����:̷����");
    return 0;
}

//�����Ǻ���ʵ�ֲ��� 

void dijkstra(int vs, int vd) {    //�������vs���յ�vd��dijkstra���� 
    int path[N], dist[N];
    int i, p, min;
    void display(int p, int s[N], int path[N], int dist[N]);
    void output(int path[N], int vs, int vd);
    s[vs] = 1; p = vs;       //p��ָs�е�ǰ��㣬��ʼΪ���VS��״̬Ϊ1
    for (i = 0; i < N; i++)
    {
        dist[i] = G[vs][i];
        if (dist[i] == inf)  //inf��������� 
            path[i] = -1;   //��ʼ����������vs������ǰ�����Ϊvs�� ����Ϊ-1
        else
            path[i] = vs;
    }
    putchar(10);
    display(p, s, path, dist);

    while (s[vd] != 1) {
        min = inf;
        for (i = 0; i < N; i++)
            if (s[i] == 0 && dist[i] < min) {
                p = i;
                min = dist[i];
            }
        s[p] = 1;       //�ҳ�һ���µ���S��㣬���Ϊ1���´β����� 

        for (i = 0; i < N; i++) {          //ɨ��S����0ֵ��Ѱ����һ���·��
            if (s[i] == 0)            //�Ƚϸ�·�����ȣ��ҳ���һ��S��� 
                if (G[p][i] < inf && G[p][i] + dist[p] < dist[i])                  //min(������p���ڽ���·������)
                {
                    dist[i] = G[p][i] + dist[p];
                    path[i] = p;
                }
        }

        display(p, s, path, dist);
    }
    printf("%c�Ѿ�����S�����������·�����Ⱦ���dist�е�%d�Ž���ֵ��%d\n", u[vd], vd, dist[vd]);
    output(path, vs, vd);
}

void display(int p, int s[N], int path[N], int dist[N]) {
    int i;
    static int count = 1;
    printf("��%d��:��ǰ������pֵָ���%d�Ž��%c\n", count, p, u[p]);
    printf("��ǰu�����н��ȫ��Ϊ:");
    for (i = 0; i < N; i++) { printf("%5c", u[i]); }
    putchar(10);     //putchar(10)Ϊ���з����൱��printf("\n") 
    printf("��ǰs�����н��״̬Ϊ:");
    for (i = 0; i < N; i++) { printf("%5d", s[i]); }
    putchar(10);
    printf("��ǰpath�н��״̬Ϊ��");
    for (i = 0; i < N; i++) { printf("%5d", path[i]); }
    putchar(10);
    printf("��ǰdist�н��״̬Ϊ��");
    for (i = 0; i < N; i++) { printf("%5d", dist[i]); }
    putchar(10);
    putchar(10);
    count++;
    system("pause");
}

void input_graph(int a[N][N]) {
    int i = 0, j = 0, m, k, w;
    int choise;    //����ͼ��������ͼѡ�� 
    char c1, c2;
    printf("�밴˳������ͼG��%d�����㼯��v:(���ո�س�����)\n", N);
    for (m = 0; m < N; m++)
        scanf("%c", &u[m]);
    putchar(getchar());    //�ѻس���������������У�����س�����Ӱ�������ַ���ȡ 
    printf("����������ͼ��������ͼ:(����ͼ����0������ͼ����1)��\n");
    scanf("%d", &choise);
    putchar(getchar());
    printf("\n������ͼ�������ϵ�����빹�ɵı߼�E:����ab 5,��01 5,��##0������\n");
    for (k = 0; k < Max_num - 1; k++) {
        scanf("%c%c %d,", &c1, &c2, &w);
        if (c1 == '#') break;
        for (m = 0; m < N; m++) {
            if (c1 == u[m])  	i = m; //ɨ�輯��A���Ա��ҵ��ڶ�ά������λ��i,j 
            if (c2 == u[m])   j = m; //��c1=a,c2=b,���ҵ�i=0,j=1,�Ӷ�a[0][1]=1 
        }
        a[i][j] = w;      //����ͼ��������Ϊ1 
        choise == 0 ? (a[j][i] = w) : (choise = 1);     //����ͼ��˫��Ϊ1 
    }
    printf("\n");
}

void display_matrix(int c[N][N]) {
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%4d", c[i][j]);
        printf("\n");
    }
    system("pause");
}

void output(int path[N], int vs, int vd) {
    int i, j, p, num = 0, temp[N] = { 0 };
    temp[0] = vd; p = vd;
    printf("\n");

    printf("������path���鵹�ݿɵã�");
    printf("%d�ŵ�   ", vd);
    while (p != vs) {
        p = path[p];
        num++;
        temp[num] = p;
        printf("%d�ŵ�  ", p);
    }
    printf("\n�����㵽�յ����·��Ϊ��");
    for (i = num; i >= 0; i--) {
        j = temp[i];
        printf("%3c    ", u[j]);
    }
    printf("\n\n");
    system("pause");
    printf("\n");
    printf("\n�ܽ᣺1��Dijkstra�㷨����������2���������ڽ�������ʱ�临�Ӷ�ΪO(nƽ��)��");
    printf("\n      2������ɨ��dist����δ����s�����·�����յ����s���ɣ�����ÿ����㶼�룻");
    printf("\n      3��ÿ��δ��s�Ľ��i���뵱ǰp�ľ���+dist[p]������dist[i]�Ƚ�ȡ��Сֵ;");
    printf("\n      4��Dijkstra�㷨�����·�����ȣ�ֻҪ��dist��ֵ���յ��Ӧֵ��");
    printf("\n      5��Dijkstra�㷨���·����path��ֵ�е��ݵõ����ǳ��� ");
}
void copyright() {
    int i;
    for (i = 0; i < 6; i++)
        printf("\n");
    system("color 0C");
    printf("��Dijkstra�㷨��ѧ�����Ȩ���ڹ���ʦ�ͼƿ�ϵȫ��ͬѧ��\n");
    printf("      ��ӭ�ƿ�ϵͬѧ��ѧϰ��������ͬ������\n");
    for (i = 0; i < 6; i++)
        printf("\n");
    system("pause");
    system("cls");
    system("color 0f");
}
