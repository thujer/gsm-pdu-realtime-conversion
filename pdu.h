
#define uchar unsigned char
                       
typedef struct struct_gsm
{
  uchar smsc[15];                // Cislo servisniho strediska
  uchar smsc_number_size;        // Pocet oktetu format cisla + cislo servisniho strediska
  uchar smsc_number_format;      // Format cisla servisniho strediska
  uchar tp_msg_ref;              // Stavove informace SMS
  uchar sms_deliver_submit;      // SMS deliver / SMS submit
  uchar sender_num_size;         // Delka cisla odesilatele/adresata
  uchar sender_num[15];          // Cislo odesilatele/adresata
  uchar sender_num_format;       // Format telefonniho cisla odesilatele/adresata
  uchar pid;                     // Typ zpravy SMS
  uchar dcs;                     // Kodovaci schema zpravy
  uchar date_year;               // Datum doruceni zpravy do centra
  uchar date_month;   
  uchar date_day;
  uchar date_hour;
  uchar date_minute;
  uchar date_second;
  uchar date_greenwitch_diff;    // Rozdil casu oproti Greenwitch ve ctvrthodinach
  uchar validity_period;         // Doba platnosti SMS
  uchar text_size;               // Delka textu SMS pred zakodovanim
  uchar num_of_octets;           // Pocet oktetu PDU SMS
  uchar pin[5];                  // PIN
};

extern struct struct_gsm idata gsm;    // GSM structure instance

extern uchar  pdu_getchar();
extern uchar  pdu_putchar(uchar Ch);
extern void   pdu_to_text(uchar src);
extern void   text_to_pdu(uchar src);
extern void   pdu_init();

extern uchar  pdu_text_inbuf;  
extern char  *pdu_get_octet();
extern void   pdu_do_octet(char byte);
extern uchar  pdu_octet_to_byte();

extern void   pdu_octet_swap(void);
extern void   pdu_octet_reset();
extern bit    pdu_incoming_octet;     

extern uchar  pdu_octet_buf[3];

extern void   pdu_incoming_message(uchar pdu_byte);

