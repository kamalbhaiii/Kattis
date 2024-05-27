from fractions import Fraction

def jointAttack (x0,x1):
    return Fraction(Fraction(x0),1) + Fraction(1,Fraction(x1))
    
def runner (itr, coeff):
    sol = 0
    
    for i in range(itr,0,-1):
        if len(coeff) < 3 and len(coeff) > 0:
            sol += jointAttack(coeff[i-2], coeff[i-1])
            break
        else:
            itr_coeff = jointAttack(coeff[i-2], coeff[i-1])
            coeff.pop(-1)
            coeff.pop(-1)
            coeff.insert(len(coeff),itr_coeff)
        
    print(sol)
        
    
itr = int(input())
coeff = input().split(" ")
runner(itr, coeff)