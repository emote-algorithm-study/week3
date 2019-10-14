# Algorithm Study Week3 - 동적 계획법

> 동적 계획법 - Dynamic Programming ; DP

## 중복된 계산을 피하는 방법

### 1. 메모이제이션 (Memoization) : Top-down 방식
계속 중복되는 계산을 제거하기 위한 테크닉. 계산된 값을 버리지 말고 저장한다는 뜻이다. 이렇게 저장되는 배열을 '캐시'라고 하며, 중간에 저장하는걸 '캐싱한다'라고 부른다.

### 2. Bottom-up 방식
가장 기본적인 값으로 특정한 값을 계산하려고 하는 것을 Bottom-up 이라고 한다. 이런 Bottom-up 방식으로 계산하는 테크닉을 다이나믹 프로그래밍이라고 한다.

> Memoization vs. Dynamic Programming
1. 메모이제이션이나 다이나믹 프로그래밍 둘 다 순환식을 계산하는 방법이다.
2. 모두 동적 계획법의 일종이라고 본다.
3. 메모이제이션은 Top-down 방식이고 실제 필요한 sub problem을 푼다.
4. 다이나믹 프로그래밍은 Bottom-up 방식이며 재귀에 수반되는 overhead가 없다.

---

## 예시 - 피보나치 수열
재귀로 풀면 보통 시간초과가 난다. 그래서 DP로 바꿔서 해결한다.

### 1.메모이제이션을 이용한 방법

``` c
    int memo[100];

    int fibonacci(int n){
        if(n<=1) //0번째, 1번째 피보나치 수
            return n; 

        if(memo[n]!= 0) //메모가 있는지 확인. 0으로 초기화 되었으므로 0이 아니라면 메모가 쓰임.
            return memo[n];
        
        memo[n] = fibonacci(n-1) + fibonacci(n-2); //작은 문제로 분할

        return memo[n];
    }
```

하위 결과를 memo에 저장해놓는다. 여기서 memo는 캐시이다.


### 2. Bottom-up 방식을 이용한 방법

``` c
    int f_data[N] = {1, 1}; //N은 정의하기 나름
    int last_pos = 1; //마지막으로 계산한 지점. 이 코드에선 이미 f_data[1]까지 정의되어 있기 때문에 1로 초기화한다.

    int f(int n){ //피보나치 수열의 제 n항을 구한다. 배열의 관점에서는 n-1번째 요소를 구하는 것.
        int i;

        if(f_dat[n-1]==0){ //아직 구한 적이 없으면 구한다.
            for(i=last_pos+1; i<n; ++i){
                f_data[i] = f_data[i-1] + f_data[i-2];
            }
            last_pos = n-1;
        }

        return f_data[n-1];
    }
```