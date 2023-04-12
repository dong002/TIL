def solution(a, b, n):
    answer = 0
    while n / a > 0.9:
        nam = n % a
        n1 = n - nam
        answer += n1 / a
        n = nam + (n1 / a)
    return answer