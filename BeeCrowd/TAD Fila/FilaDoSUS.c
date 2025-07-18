#include <stdio.h>

int main() {
    int n;
    
    while (scanf("%d", &n) == 1 && n != 0) {
        int critical_count = 0;
        int next_service_time = 0;
        
        for (int i = 0; i < n; i++) {
            int h, m, c;
            scanf("%d %d %d", &h, &m, &c);
            
            int arrival_time = (h - 7) * 60 + m;
            int critical_time = arrival_time + c;
            
            int earliest_service = (arrival_time > next_service_time) ? arrival_time : next_service_time;
            int service_time = ((earliest_service + 29) / 30) * 30;
            
            if (critical_time < service_time) {
                critical_count++;
            }
            
            next_service_time = service_time + 30;
        }
        
        printf("%d\n", critical_count);
    }
    
    return 0;
}