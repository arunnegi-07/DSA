**Prerequisite :**
```
    You should know how digit by digit multiplication works :

    Let us say we want to multiply : 567 * 8

    so, intead of multiplying directly we will pick remove digits form right side and then
    we will multiply it with '8' if any 'carry' is there we will add it furthur and keep on adding the
    value, let us see how :
     
    Initially, carry = 0  and  let's say N = 567 :
    take result = "" (string variable)  --> we will keep on attaching the answer to it.
    This is just a example, you can use anything like array or vector to store the result, just little
    bit changes will be present, logic will remain same.

    1st Iteration :
                digit = N % 10 --> 567 % 10 = 7 (We have picked last digit of our number)

        Now, multiply that digit with '8' and add the carry (initially it is Zero) :

                val =  digit * 8 + carry = 7 * 8 + 0 = 56

                so, rem = val % 10 = 56 % 10 = 6 
                and, carry = val / 10 = 56 / 10 = 5 

            Now, attached that remainder to the 'result' i.e result = '6'
        
        and update the number to :
                                    N = 567 / 10 = 56  
                means we are done with digit '7' and only two digits are remaining

    2nd Iteration :
                      digit = N % 10 --> 56 % 10 = 6 (We have picked last digit of the remaining number)

        Now, multiply that digit with '8' and add the carry (this time 'carry' is '5'):

                val =  digit * 8 + carry = 6 * 8 + 5 = 53

                so, rem = 53 % 10 = 3
                and, carry = 53 / 10 = 5 

            Now, attached that remainder to the 'result' i.e result = '63'

            Note : We are attaching from the back, so at the end to simply reverse our result.
            
            and update the number to :
                    N = 56 / 10 = 5 (now only 1 digit is remaining)  

    3rd Iteration :
                    digit = N % 10 --> 5 % 10 = 5 

        Now, multiply that digit with '8' and add the carry (this time 'carry' is '5'):

                val =  digit * 8 + carry = 5 * 8 + 5 = 45

                so, rem = 45 % 10 = 5
                and, carry = 45 / 10 = 4 

            Now, attached that remainder to the 'result' i.e result = '635'
        
            and update the number to :
                    N = 5 / 10 = 0 (so, we are done with all digits)

    Now, at the end just check if 'carry' is having any non-zero value present in it or not
    if it has then keep on dividing the 'carry' by 10 and add the remainder to the 'result' 
    until it become zero.

        so, we have carry = 4  
            so if we do --> carry % 10 --> 4 % 10 = 4 

              Adding that '4' to our result ---> result = '6354' 

        and update carry as --> carry / 10 --> carry = 4 / 10 = 0

    So, carry also become Zero and we are done with our multiplication and our final 
    answer is stored in the 'result' varible.

        i.e  result = '6354'   and if we reverse it we will get --> '4536' which is actually the
        multiplication of 567 * 8 
```

So, on the basis of this **hint** you can try solving this problem before jumping to actual explaination. 