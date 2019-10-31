/*
 * Author    Sejin Jeon
 * Date      2019-10-10
 * URL       https://leetcode.com/problems/maximum-swap
 * Approach  pseudo DP
 */

public class MaximumSwap {
    public int maximumSwap(int num) {
        int[] arr = convertToArr(num);
        int arrLen = arr.length;
        int[] maxValArr = new int[arrLen];
        int[] maxIdxArr = new int[arrLen];

        int maxNum = -1;
        int maxIdx = -1;
        for (int i = arrLen - 1; i >= 0; i--) {
            if (arr[i] > maxNum) {
                maxNum = arr[i];
                maxIdx = i;
            }
            maxValArr[i] = maxNum;
            maxIdxArr[i] = maxIdx;
        }

        for (int i = 0; i < arrLen; i++) {
            if (arr[i] != maxValArr[i]) {
                int tmp = arr[i];
                arr[i] = maxValArr[i];
                arr[maxIdxArr[i]] = tmp;
                break;
            }
        }

        return convertToInt(arr);
    }

    private int getNumDigits(int num) {
        int numDigits = 0;
        while (num > 0) {
            num /= 10;
            numDigits++;
        }
        return numDigits;
    }

    private int[] convertToArr(int num) {
        int numDigits = getNumDigits(num);
        int[] arr = new int[numDigits];
        int idx = numDigits - 1;
        while (num > 0) {
            arr[idx--] = (num % 10);
            num /= 10;
        }
        return arr;
    }

    private int convertToInt(int[] arr) {
        int num = 0;
        int radix = 1;
        int arrLen = arr.length;
        for (int i = arrLen - 1; i >= 0; i--) {
            num += (radix * arr[i]);
            radix *= 10;
        }
        return num;
    }
}
