// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int size, int value) {
    int cnt = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if ((arr[i] + arr[j]) == value)
                cnt += 1;
    return cnt;
}
int countPairs2(int* arr, int len, int value) {
    int cnt = 0;
    int left = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right = right - 1;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            int summ = arr[i] + arr[j];
            if (summ == value) {
                cnt++;
            }
        }
    }
    return cnt;
}
int cbinsearch(int* arr, int size, int value) {
    int cnt = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            cnt++;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && arr[left] == value) {
                cnt++;
                left--;
            }
            while (right < size && arr[right] == value) {
                cnt++;
                right++;
            }
            return cnt;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return cnt;
}
int countPairs3(int* arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        int second = value - arr[i];
        cnt += cbinsearch(&arr[i + 1], len - i - 1, second);
    }
    return cnt;
}
