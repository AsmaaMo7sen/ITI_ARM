
#ifndef BIT_MATHS_H_
#define	BIT_MATHS_H_

//This Function is to Set a Specific Bit in a Variable
#define SET_BIT(VAR , BIT)    (VAR |= (1 << BIT))

//This Function is to Clear a Specific Bit in a Variable
#define CLR_BIT(VAR , BIT)    (VAR &= (~(1 << BIT)))

//This Function is to Toggle a Specific Bit in a Variable
#define TGL_BIT(VAR , BIT)    (VAR ^= (1 << BIT))

//This Function is to Get the Value of a Specific Bit in a Variable
#define GET_BIT(VAR , BIT)    ((VAR >> BIT) & 1)

//This Function is to Set a Value (0 | 1) to a Specific Bit in a Variable
#define WRT_BIT(VAR , BIT , BIT_VALUE)  (VAR = (BIT_VALUE << BIT) | (VAR &= (~(1 << BIT))))

#endif
