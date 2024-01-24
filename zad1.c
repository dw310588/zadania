#include <stdio.h>

int main() {
    int curr;
    int sum = 0;
    int count = 0;
    int count_in_range = 0;
    int odds_count = 0;
    while(curr <= 15 && odds_count < 3) {
        scanf("%i",&curr);
        if(curr > 15) {
            sum++;
        }
        if(curr % 2 == 1) {
            odds_count++;
        }
        if(curr >= -6 && curr <= 6) {
            sum += curr;
            count_in_range++;
        }
        count++;
    }
    if(count == 1) {
        printf("Not enough valid numbers\n");
    } else {
        float avg = (float) sum / count_in_range;
        int even_count = count - odds_count;
        printf("Even count - %i\n",even_count);
        printf("Avg - %f\n",avg);
        printf("Range count - %i\n",count_in_range);
    }
    return 0;
}
