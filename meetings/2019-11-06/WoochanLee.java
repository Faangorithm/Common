/*	
 * Author    Woochan Lee	
 * Date      2019-11-06	
 * URL       https://leetcode.com/problems/gas-station/	
 * Approach  pseudo DP	
 */	
 
class WoochanLee {	
    public int canCompleteCircuit(int[] gas, int[] cost) {	

        int[] diffArr = new int[gas.length];	

        for(int i=0;i<gas.length;i++){	
            diffArr[i] = gas[i] - cost[i];	
        }	

        boolean no = false;	
        for(int i=0;i<diffArr.length;i++){	
            if(no){	
                if(diffArr[i]>=0){	
                    continue;	
                }else {	
                    no = false;	
                }	
            }	
            if(diffArr[i]<0){	
                continue;	
            }else {	
                int sum = 0;	
                boolean isFail = false;	
                for(int j=0;j<diffArr.length;j++){	
                    sum += diffArr[(i+j)%diffArr.length];	
                    if(sum < 0){	
                        isFail = true;	
                        no = true;	
                        break;	
                    }	
                }	
                if(!isFail){	
                    return i;	
                }	
            }	
        }	
        return -1;	
    }	
} 