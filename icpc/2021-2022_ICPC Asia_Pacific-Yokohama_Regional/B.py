import sys

input = sys.stdin.readline

n = int(input())

lotto = list()

cnt_four = dict()
cnt_two = dict()

for i in range(n):
    lotto.append(input().strip())
    last_four = lotto[i][-4:]
    last_two = lotto[i][-2:]
    if last_four not in cnt_four:
        cnt_four[last_four] = 0
    cnt_four[last_four] += 1
    if last_two not in cnt_two:
        cnt_two[last_two] = 0
    cnt_two[last_two] += 1

done_two = dict()
done_four = dict()

for i in range(n):
    last_four = lotto[i][-4:]
    last_two = lotto[i][-2:]
    if last_two not in done_two:
        done_two[last_two] = True
        st_two.append((cnt_two[last_two], last_two))
    if last_four not in done_four:
        done_four[last_four] = True
        st_four.append((cnt_four[last_four], last_four))

st_two.sort()
st_four.sort()

# permute ?
# do {
#     if(a[i] == )
# }while(next_permutation())