//facebook.com/george.laz

char uart_rd;

void main()
{
 USART_Init(9600); //Set Baud Rate
 Delay_ms(100); //wait 100ms stabilizing connection

 TRISB = 0; //ALL PORTB AS OUTPUT
 PORTB = 0; //ALL PORTB START OFF
 TRISD = 0; //ALL PORTD AS OUTPUT
 PORTD = 0; //ALL PORTD START OFF

while(1)
  {
   uart_rd = 0; //preset 0 Data

    if (USART_Data_Ready()) //if uart is ready start working
   {
     uart_rd = USART_Read(); //SET uart_Read as uart_rd Reading data
     USART_Write(uart_rd); // Read the received data
   }

      switch(uart_rd) //Write the transfered data
       {
         //PORTB.F0 = 1 start motor LEFT M4 then Stop PORTB.F0 = 0 motor after 1000ms
         case '1' : PORTB.F0 = 1; Delay_ms(1000); PORTB.F0 = 0; break; 
         //PORTB.F1 = 1 start motor RIGHT M4 then Stop PORTB.F1 = 0 motor after 1000ms
         case 'q' : PORTB.F1 = 1; Delay_ms(1000); PORTB.F1 = 0; break;
         //PORTD.F6 = 1 start motor UP M3 then Stop PORTD.F6 = 0 motor after 1000ms
         case '2' : PORTD.F6 = 1; Delay_ms(1000); PORTD.F6 = 0; break;
         //PORTD.F7 = 1 start motor DOWN M3 then Stop PORTD.F7 = 0 motor after 1000ms
         case 'w' : PORTD.F7 = 1; Delay_ms(1000); PORTD.F7 = 0; break;
         //PORTD.F4 = 1 start motor UP M2 then Stop PORTD.F4 = 0 motor after 1000ms
         case 'e' : PORTD.F4 = 1; Delay_ms(1000); PORTD.F4 = 0; break; 
         //PORTD.F5 = 1 start motor DOWN M2 then Stop PORTD.F5 = 0 motor after 1000ms
         case '3' : PORTD.F5 = 1; Delay_ms(1000); PORTD.F5 = 0; break; 
         //PORTD.F2 = 1 start motor UP M1 then Stop PORTD.F2 = 0 motor after 1000ms
         case '4' : PORTD.F2 = 1; Delay_ms(1000); PORTD.F2 = 0; break;
         //PORTD.F3 = 1 start motor Down M1 then Stop PORTD.F3 = 0 motor after 1000ms
         case 'r' : PORTD.F3 = 1; Delay_ms(1000); PORTD.F3 = 0; break; 
         //PORTD.F0 = 1 start motor OPEN M0 then Stop PORTD.F0 = 0 motor after 1000ms
         case 'o' : PORTD.F0 = 1; Delay_ms(1000); PORTD.F0 = 0; break;
         //PORTd.F1 = 1 start motor CLOSE M0 then Start PORTD.F0 = 0 motor after 1000ms
         case 'c' : PORTD.F1 = 1; Delay_ms(1000); PORTD.F1 = 0; break; 
         //PORTB.F4 = 0 LED ON
         case 'l' : PORTB.F4 = 0; break;
         //PORTB.F4 = 0 LED OFF
         case ';' : PORTB.F4 = 1; break;
        }
   }
}
