void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int index = 0;
    for (int i = 0; i < nums2Size; i ++) {
        while (nums1[index] <= nums2[i] && index != m) {
            index ++;
        }

        if (nums1[index] > nums2[i]) {
            for (int j = m; j > index; j --) {
                nums1[j] = nums1[j - 1];
            }
        }
        nums1[index] = nums2[i];
        m ++;
    }
}
