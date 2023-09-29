int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    int sum_duration = 0;
    int now = timeSeries[0];

    for (int i = 1; i < timeSeriesSize; i ++) {
        if (now + duration > timeSeries[i]) {
            sum_duration += timeSeries[i] - now;
        } else {
            sum_duration += duration;
        }

        now = timeSeries[i];
    }

    sum_duration += duration;

    return sum_duration;
}
