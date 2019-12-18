//Dara Lim
//CS3130
//Project1 part D

import java.util.Scanner;

public class FibArrDigit {
	public static void main(String[] args) {
        int number;
		int sizeArr = 100;
		Scanner input = new Scanner(System.in);
		System.out.print("Please enter the integer number : ");
		number = input.nextInt();
		
		System.out.print("The Fibonacci integer numbers between F(2) to F(" + number + ") are: \n\t");
		for (int i = 2; i <= number; i++) {
			int[] fib1 = getArrayOfFib(i, sizeArr);
			System.out.print(StringFromIntArr(fib1) + " ");
		}
		
		int numDig;
		while (true) {
			System.out.print("\nThe largest Fibonnaci number that has less than 100 digits"
					+ ".\nEnter the size you want to display: ");
			numDig = input.nextInt();
            if (numDig >= 100){
                System.out.print("The digit is 100 or more, the program is done! \n");
                break;
            }
			showLargestFib(numDig);
		}
		
	}
	
    private static String StringFromIntArr(int[] value) {
        String output = FromArrayToString(value);
        output = EraseZerosInFront(output);
        
        return output;
    }
    
    private static int[] addArrays(int[] firstArray, int[] secondArray) {
        int sizeArr = firstArray.length;
        int[] thirdArray = new int[sizeArr + 1];
        for (int i = 0; i < sizeArr; i++) {
            thirdArray[i] = 0;
        }
        
        int carry = 0;
        for (int i = sizeArr - 1; i >= 0; i--) {
            int tmp = firstArray[i] + secondArray[i] + carry;
            thirdArray[i + 1] = tmp % 10;
            carry = tmp / 10;
        }
        thirdArray[0] = carry;
        
        return thirdArray;
    }
    
    private static int[] getArrayOfFib(int number, int sizeArr) {
        // Return F(n) in the form of an array, with (size + 1) elements
        int[] firstFibArr = new int[sizeArr];
        int[] secondFibArr = new int[sizeArr];
        int[] thirdFibArr = new int [sizeArr + 1];
        
        // Initially set up
        for (int i = 0; i < sizeArr; i++) {
            firstFibArr[i] = secondFibArr[i] = thirdFibArr[i] = 0;
        }
        
        if (number==0) {
            return (addArrays(firstFibArr, firstFibArr));
        }
        
        if (number==1) {
            secondFibArr[sizeArr - 1] = 1;
            return (addArrays(firstFibArr, secondFibArr));
        }
        
        secondFibArr[sizeArr - 1] = 1;
        for (int i = 0; i < number - 1; i++) {
            thirdFibArr = addArrays(firstFibArr, secondFibArr);
            firstFibArr = secondFibArr;
            
            int[] secondFibArrTmp = new int[secondFibArr.length];
            for (int j = 0; j < secondFibArr.length; j++) {
                secondFibArrTmp[j] = thirdFibArr[j + 1];
            }
            secondFibArr = secondFibArrTmp;
            
        }
        
        return thirdFibArr;
    }
    
	private static String LargestFib(int sizeArr) {

		String output = "";
		int number = 0;
		int[] fibona;
		
		if (sizeArr == 2)
			return "8";
		
		while (true) {	
			fibona = getArrayOfFib(number, sizeArr - 2);
			
			if (fibona[0] != 0)
				break;
			number++;
		}	
		int l = number;
		
		int[] fA;
		while (true) {
			fA = getArrayOfFib(number, sizeArr - 1);
			
			if (fA[0] != 0)
				break;
			number++;
		}	
		int h = number;
		
		for (int j = l; j <= h; j++) {
			int[] f = getArrayOfFib(j, sizeArr - 1);
			if (StringFromIntArr(f).length() >= sizeArr) {
				number = j - 1;
				break;
			}
		}
		
		output = StringFromIntArr(getArrayOfFib(number, sizeArr - 1));
		
		return output;
	}
    
    private static void showLargestFib(int sizeArr) {
        
        String largeFib = LargestFib(sizeArr);
        
        System.out.println("The biggest Fibonacci number that has less than "
                           + sizeArr + " digits is:\n\t" + largeFib);
    }
    
	
    private static String FromArrayToString(int[] aa) {
        String str = "";
        for (int j = 0; j < aa.length; j++) {
            str = str + aa[j];
        }
        return str;
    }
	
	private static String EraseZerosInFront(String str) {
		if (str.length() < 2)
			return str;
		
		int j;
		for (j = 0; j < str.length() - 1; j++) {
			char ch = str.charAt(j);
			if (ch != '0')
				break;
		}
		
		if (j == 0) {
			return str;
		}
		
		return str.substring(j);
		
	}

}
