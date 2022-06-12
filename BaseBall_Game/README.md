비트 연산을 이용하여 야구게임 구현 

기본 logic (비트연산 사용 안하고 for문으로 나타냄)

ㅣ0. 0으로 초기화 한 s, b 생성
- s, b의 범위, 연산 규칙 --> 속도(int) , 메모리(int) 
1. 난수로 3개의 P_n(n=3) 생성 
- n배열, n 구조체
- 의사난수(수열 1_C_32) : srandom():seed 설정 random():seed 기준 무작위 수열 생성 0~Max_int | 의사: 약간 흉내느낌,  진짜가 아닌   seed: 초기값     
- P[0] = random() % 10
- do{
      p[1] = random() % 10
  }while(P[0] == P[1]);
  do{
      p[2] = random() % 10
  }while(P[0] == P[2]);
  do{
      p[2] = random() % 10
  }while(P[2] == P[0] || P[1] == P[2]);
  
2. 사용자 입력을 U_n(n=3) 대입
- n 배열
- scanf("%d %d %d", U[0],U[1],U[2]);


3. U_n와 P_m 숫자 비교 

  3-1.  P_n과 U_n 사용자 숫자가 같은 지 비교 맞으면 s++
  for( int i = 0; i < 3; i++){
     if(P[i] == U[i]) s++;
  }

  3-2.  n != m일 때 P_m과 U_n이 같으면 b 값 증가
  if (n != m && P_m==U_n){
      b++;
  }

0. 입력 -> 처리 -> 출력
1. 초기화 : void init(void)
 - P_n 생성
2. 입력   : void input(void)
 - U_n 대입
3. 처리   : void process(void)
 - P_n == U_n 비교 P_m == U_n
4. 출력   : void show(void)
 - s, b
if(s == 3) 종료
else 2. 실행 
