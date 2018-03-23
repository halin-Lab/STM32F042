#ifndef __RC522_FUNCTION_H
#define	__RC522_FUNCTION_H


#include "stm32_it.h"


#define          macDummy_Data              0x00


void             PcdReset                   ( void );                       //��λ
void             M500PcdConfigISOType       ( uint8_t type );                    //������ʽ
char             PcdRequest                 ( uint8_t req_code, uint8_t * pTagType ); //Ѱ��
char             PcdAnticoll                ( uint8_t * pSnr);                   //������

char PcdAuthState ( uint8_t ucAuth_mode, uint8_t ucAddr, uint8_t * pKey, uint8_t * pSnr );
char PcdSelect ( uint8_t * pSnr );
char PcdAnticoll ( uint8_t * pSnr );
char PcdHalt( void );
char PcdWrite ( uint8_t ucAddr, uint8_t * pData );
#endif /* __RC522_FUNCTION_H */
