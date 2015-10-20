#ifdef __linux__
#include <strings.h>
#define stricmp strcasecmp
#define strnicmp strncasecmp
#endif
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <stdlib.h>
//using namespace std;
int main(int argc, char *argv[]) {
 srand(time(NULL));
 bool even_only = false;
 bool odd_only = false;
 bool output_random = false;
 bool use_lower = false;
 bool use_upper = false;
 bool use_len_8 = false;
 bool use_len_9 = false;
 bool no_0 = false;
 bool no_1 = false;
 int desired_uniques = 0;
 int min_uniques = 6;
 int max_uniques = 9;
 int slot1_start_at = 0;
 int slot1_stop_at = 0;
 bool starts_with_letter = false;
 bool make_next_start_at = false;
 bool make_next_stop_at = false;
 int make_next_start_at_cnt = 0;
 int make_next_stop_at_cnt = 0;
 unsigned long long int start_at_long = 0;
 unsigned long long int stop_at_long = 0;
 if (argc > 1) {
  for (int i=1;i<argc;++i) {
   if (stricmp(argv[i], "-evenonly") == 0) { even_only = true; }
   if (stricmp(argv[i], "-oddonly") == 0) { odd_only = true; }
   if (stricmp(argv[i], "-random") == 0) { output_random = true; }
   if (stricmp(argv[i], "-lower") == 0) { use_lower = true; }
   if (stricmp(argv[i], "-upper") == 0) { use_upper = true; }
   if (stricmp(argv[i], "-len8") == 0) { use_len_8 = true; }
   if (stricmp(argv[i], "-len9") == 0) { use_len_9 = true; }
   if (stricmp(argv[i], "-no0") == 0) { no_0 = true; }
   if (stricmp(argv[i], "-no1") == 0) { no_1 = true; }
   if (stricmp(argv[i], "-no01") == 0) { no_0 = true; no_1 = true; }
   if (stricmp(argv[i], "-no10") == 0) { no_0 = true; no_1 = true; }
   if (stricmp(argv[i], "-1unique") == 0) { desired_uniques = min_uniques = max_uniques = 1; }
   if (stricmp(argv[i], "-2uniques") == 0) { desired_uniques = min_uniques = max_uniques = 2; }
   if (stricmp(argv[i], "-3uniques") == 0) { desired_uniques = min_uniques = max_uniques = 3; }
   if (stricmp(argv[i], "-4uniques") == 0) { desired_uniques = min_uniques = max_uniques = 4; }
   if (stricmp(argv[i], "-5uniques") == 0) { desired_uniques = min_uniques = max_uniques = 5; }
   if (stricmp(argv[i], "-6uniques") == 0) { desired_uniques = min_uniques = max_uniques = 6; }
   if (stricmp(argv[i], "-7uniques") == 0) { desired_uniques = min_uniques = max_uniques = 7; }
   if (stricmp(argv[i], "-8uniques") == 0) { desired_uniques = min_uniques = max_uniques = 8; }
   if (stricmp(argv[i], "-9uniques") == 0) { desired_uniques = min_uniques = max_uniques = 9; }
   if (stricmp(argv[i], "-10uniques") == 0) { desired_uniques = min_uniques = max_uniques = 10; }
   if (stricmp(argv[i], "-1minunique") == 0) { min_uniques = 1; }  if (stricmp(argv[i], "-minunique1") == 0) { min_uniques = 1; }  if (stricmp(argv[i], "-min1unique") == 0) { min_uniques = 1; }
   if (stricmp(argv[i], "-2minuniques") == 0) { min_uniques = 2; } if (stricmp(argv[i], "-minuniques2") == 0) { min_uniques = 2; } if (stricmp(argv[i], "-min2uniques") == 0) { min_uniques = 2; }
   if (stricmp(argv[i], "-3minuniques") == 0) { min_uniques = 3; } if (stricmp(argv[i], "-minuniques3") == 0) { min_uniques = 3; } if (stricmp(argv[i], "-min3uniques") == 0) { min_uniques = 3; }
   if (stricmp(argv[i], "-4minuniques") == 0) { min_uniques = 4; } if (stricmp(argv[i], "-minuniques4") == 0) { min_uniques = 4; } if (stricmp(argv[i], "-min4uniques") == 0) { min_uniques = 4; }
   if (stricmp(argv[i], "-5minuniques") == 0) { min_uniques = 5; } if (stricmp(argv[i], "-minuniques5") == 0) { min_uniques = 5; } if (stricmp(argv[i], "-min5uniques") == 0) { min_uniques = 5; }
   if (stricmp(argv[i], "-6minuniques") == 0) { min_uniques = 6; } if (stricmp(argv[i], "-minuniques6") == 0) { min_uniques = 6; } if (stricmp(argv[i], "-min6uniques") == 0) { min_uniques = 6; }
   if (stricmp(argv[i], "-7minuniques") == 0) { min_uniques = 7; } if (stricmp(argv[i], "-minuniques7") == 0) { min_uniques = 7; } if (stricmp(argv[i], "-min7uniques") == 0) { min_uniques = 7; }
   if (stricmp(argv[i], "-8minuniques") == 0) { min_uniques = 8; } if (stricmp(argv[i], "-minuniques8") == 0) { min_uniques = 8; } if (stricmp(argv[i], "-min8uniques") == 0) { min_uniques = 8; }
   if (stricmp(argv[i], "-9minuniques") == 0) { min_uniques = 9; } if (stricmp(argv[i], "-minuniques9") == 0) { min_uniques = 9; } if (stricmp(argv[i], "-min9uniques") == 0) { min_uniques = 9; }
   if (stricmp(argv[i], "-10minuniques") == 0) { min_uniques = 10; } if (stricmp(argv[i], "-minuniques10") == 0) { min_uniques = 10; } if (stricmp(argv[i], "-min10uniques") == 0) { min_uniques = 10; }
   if (stricmp(argv[i], "-1maxunique") == 0) { max_uniques = 1; }  if (stricmp(argv[i], "-maxunique1") == 0) { max_uniques = 1; }  if (stricmp(argv[i], "-max1unique") == 0) { max_uniques = 1; }
   if (stricmp(argv[i], "-2maxuniques") == 0) { max_uniques = 2; } if (stricmp(argv[i], "-maxuniques2") == 0) { max_uniques = 2; } if (stricmp(argv[i], "-max2uniques") == 0) { max_uniques = 2; }
   if (stricmp(argv[i], "-3maxuniques") == 0) { max_uniques = 3; } if (stricmp(argv[i], "-maxuniques3") == 0) { max_uniques = 3; } if (stricmp(argv[i], "-max3uniques") == 0) { max_uniques = 3; }
   if (stricmp(argv[i], "-4maxuniques") == 0) { max_uniques = 4; } if (stricmp(argv[i], "-maxuniques4") == 0) { max_uniques = 4; } if (stricmp(argv[i], "-max4uniques") == 0) { max_uniques = 4; }
   if (stricmp(argv[i], "-5maxuniques") == 0) { max_uniques = 5; } if (stricmp(argv[i], "-maxuniques5") == 0) { max_uniques = 5; } if (stricmp(argv[i], "-max5uniques") == 0) { max_uniques = 5; }
   if (stricmp(argv[i], "-6maxuniques") == 0) { max_uniques = 6; } if (stricmp(argv[i], "-maxuniques6") == 0) { max_uniques = 6; } if (stricmp(argv[i], "-max6uniques") == 0) { max_uniques = 6; }
   if (stricmp(argv[i], "-7maxuniques") == 0) { max_uniques = 7; } if (stricmp(argv[i], "-maxuniques7") == 0) { max_uniques = 7; } if (stricmp(argv[i], "-max7uniques") == 0) { max_uniques = 7; }
   if (stricmp(argv[i], "-8maxuniques") == 0) { max_uniques = 8; } if (stricmp(argv[i], "-maxuniques8") == 0) { max_uniques = 8; } if (stricmp(argv[i], "-max8uniques") == 0) { max_uniques = 8; }
   if (stricmp(argv[i], "-9maxuniques") == 0) { max_uniques = 9; } if (stricmp(argv[i], "-maxuniques9") == 0) { max_uniques = 9; } if (stricmp(argv[i], "-max9uniques") == 0) { max_uniques = 9; }
   if (stricmp(argv[i], "-10maxuniques") == 0) { max_uniques = 10; } if (stricmp(argv[i], "-maxuniques10") == 0) { max_uniques = 10; } if (stricmp(argv[i], "-max10uniques") == 0) { max_uniques = 10; }
   if (stricmp(argv[i], "-startswith0") == 0) { slot1_start_at = 0; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswith1") == 0) { slot1_start_at = 1; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswith2") == 0) { slot1_start_at = 2; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswith3") == 0) { slot1_start_at = 3; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswith4") == 0) { slot1_start_at = 4; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswith5") == 0) { slot1_start_at = 5; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswith6") == 0) { slot1_start_at = 6; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswith7") == 0) { slot1_start_at = 7; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswith8") == 0) { slot1_start_at = 8; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswith9") == 0) { slot1_start_at = 9; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswithA") == 0) { slot1_start_at = 10; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswithB") == 0) { slot1_start_at = 11; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswithC") == 0) { slot1_start_at = 12; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswithD") == 0) { slot1_start_at = 13; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswithE") == 0) { slot1_start_at = 14; starts_with_letter = true; }
   if (stricmp(argv[i], "-startswithF") == 0) { slot1_start_at = 15; starts_with_letter = true; }
   if (stricmp(argv[i], "-start") == 0) { make_next_start_at = true; make_next_start_at_cnt = i; }
   if (stricmp(argv[i], "-stop") == 0) { make_next_stop_at = true; make_next_stop_at_cnt = i; }
   if ((make_next_start_at) && (i == (make_next_start_at_cnt+1))) { std::istringstream str_to_num(argv[i]); str_to_num >> start_at_long; if (!str_to_num) {std::cout << "ERROR: start is not a number" << std::endl; return 1;} make_next_start_at = false; }
   if ((make_next_stop_at) && (i == (make_next_stop_at_cnt+1))) { std::istringstream str_to_num(argv[i]); str_to_num >> stop_at_long; if (!str_to_num) {std::cout << "ERROR: stop is not a number" << std::endl; return 1;} make_next_stop_at = false; }
  }
 }
 if ((stop_at_long !=0) && (stop_at_long <= start_at_long)) { std::cout << "ERROR: stop must be greater than start" << std::endl; return 1; }

 const int MAX_LENGTH = 10;
 char hex_chars[MAX_LENGTH];
 for (int i=0;i<MAX_LENGTH;++i) { hex_chars[i] = '0'; }
 char possible_chars[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
 int possible_chars_freq[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 int possible_chars_length = sizeof(possible_chars);
 if (use_lower) {for (int i=0;i<possible_chars_length;++i) { possible_chars[i] = tolower(possible_chars[i]); }}
 if (use_upper) {for (int i=0;i<possible_chars_length;++i) { possible_chars[i] = toupper(possible_chars[i]); }}
 int start_at = 0;
 if (no_0) { start_at = 1; }
 if (no_1) { start_at = 2; }
 int random_number = 0;
 int unique_count = 0;
 unsigned long long int counter = 0;
 unsigned long long int uniques_counter[MAX_LENGTH];
 for (int i=0;i<MAX_LENGTH;++i) { uniques_counter[i] = 0; }
 if (starts_with_letter == false) { slot1_start_at = start_at; }
 slot1_stop_at = (starts_with_letter) ? (slot1_start_at + 1) : possible_chars_length;

// generate random combinations
 if (output_random) {
  for (unsigned long long int j=0;j<1099511627776;++j) {
   possible_chars_freq[0]=possible_chars_freq[1]=possible_chars_freq[2]=possible_chars_freq[3]=possible_chars_freq[4]=possible_chars_freq[5]=possible_chars_freq[6]=possible_chars_freq[7]=possible_chars_freq[8]=possible_chars_freq[9]=possible_chars_freq[10]=possible_chars_freq[11]=possible_chars_freq[12]=possible_chars_freq[13]=possible_chars_freq[14]=possible_chars_freq[15]=0;
   for(int i=0;i<MAX_LENGTH;++i) {
    random_number = rand() % possible_chars_length;
    if ((random_number==0)&&(no_0)) { while (random_number == 0) { random_number = rand() % possible_chars_length; } }
    if ((random_number==1)&&(no_1)) { while (random_number == 1) { random_number = rand() % possible_chars_length; } }
    if ((odd_only)&&(i==(MAX_LENGTH-1))&&(random_number%2==0)) { i=MAX_LENGTH-2; continue; }
    if ((even_only)&&(i==(MAX_LENGTH-1))&&(random_number%2!=0)) { i=MAX_LENGTH-2; continue; }
    hex_chars[i] = possible_chars[random_number];
    ++possible_chars_freq[random_number];
   }
   if (use_len_8) {
    if ((possible_chars_freq[0]+possible_chars_freq[1]+possible_chars_freq[2]+possible_chars_freq[3]+possible_chars_freq[4]+possible_chars_freq[5]+possible_chars_freq[6]+possible_chars_freq[7]+possible_chars_freq[8]+possible_chars_freq[9]) >= 7) { continue; } // cannot contain 7+ numbers
    std::cout << hex_chars[0] << hex_chars[1] << hex_chars[2] << hex_chars[3] << hex_chars[4] << hex_chars[5] << hex_chars[6] << hex_chars[7] << std::endl;
   }
   else if (use_len_9) {
    if ((possible_chars_freq[0]+possible_chars_freq[1]+possible_chars_freq[2]+possible_chars_freq[3]+possible_chars_freq[4]+possible_chars_freq[5]+possible_chars_freq[6]+possible_chars_freq[7]+possible_chars_freq[8]+possible_chars_freq[9]) >= 8) { continue; } // cannot contain 8+ numbers
    std::cout << hex_chars[0] << hex_chars[1] << hex_chars[2] << hex_chars[3] << hex_chars[4] << hex_chars[5] << hex_chars[6] << hex_chars[7] << hex_chars[8] << std::endl;
   }
   else {
    if ((possible_chars_freq[10]+possible_chars_freq[11]+possible_chars_freq[12]+possible_chars_freq[13]+possible_chars_freq[14]+possible_chars_freq[15]) >= 9) { continue; } // cannot contain 9+ letters
    if ((possible_chars_freq[0]+possible_chars_freq[1]+possible_chars_freq[2]+possible_chars_freq[3]+possible_chars_freq[4]+possible_chars_freq[5]+possible_chars_freq[6]+possible_chars_freq[7]+possible_chars_freq[8]+possible_chars_freq[9]) >= 9) { continue; } // cannot contain 9+ numbers
    if ((possible_chars_freq[0]>3)||(possible_chars_freq[1]>3)||(possible_chars_freq[2]>3)||(possible_chars_freq[3]>3)||(possible_chars_freq[4]>3)||(possible_chars_freq[5]>3)||(possible_chars_freq[6]>3)||(possible_chars_freq[7]>3)||(possible_chars_freq[8]>3)||(possible_chars_freq[9]>3)||(possible_chars_freq[10]>3)||(possible_chars_freq[11]>3)||(possible_chars_freq[12]>3)||(possible_chars_freq[13]>3)||(possible_chars_freq[14]>3)||(possible_chars_freq[15]>3)) { continue; } // each character cannot appear more than 3 times
    unique_count = ((possible_chars_freq[0]!=0)?1:0) + ((possible_chars_freq[1]!=0)?1:0) + ((possible_chars_freq[2]!=0)?1:0) + ((possible_chars_freq[3]!=0)?1:0) + ((possible_chars_freq[4]!=0)?1:0) + ((possible_chars_freq[5]!=0)?1:0) + ((possible_chars_freq[6]!=0)?1:0) + ((possible_chars_freq[7]!=0)?1:0) + ((possible_chars_freq[8]!=0)?1:0) + ((possible_chars_freq[9]!=0)?1:0) + ((possible_chars_freq[10]!=0)?1:0) + ((possible_chars_freq[11]!=0)?1:0) + ((possible_chars_freq[12]!=0)?1:0) + ((possible_chars_freq[13]!=0)?1:0) + ((possible_chars_freq[14]!=0)?1:0) + ((possible_chars_freq[15]!=0)?1:0);
    if (((desired_uniques==0)&&(min_uniques==0)) || (desired_uniques==unique_count) || ((desired_uniques==0)&&(min_uniques>0)&&(unique_count>=min_uniques)&&(unique_count<=max_uniques))) {
     std::cout << hex_chars[0] << hex_chars[1] << hex_chars[2] << hex_chars[3] << hex_chars[4] << hex_chars[5] << hex_chars[6] << hex_chars[7] << hex_chars[8] << hex_chars[9] << std::endl;
    }
   }
  }
 }

// generate sequential combinations
 else {

 // ---------------------------------------------------
 // Number of combinations (10-length)
 // ---------------------------------------------------
 //  # of combos (10-length) = 1,099,511,627,776 (16^10)
 //  # of combos (10-length) with rules = 799,711,022,334 (73%)
 //  # of combos (10-length) with rules (10 uniques): 27,225,599,202 (2.5%)
 //  # of combos (10-length) with rules (09 uniques): 163,020,044,467 (15%)
 //  # of combos (10-length) with rules (08 uniques): 306,840,688,714 (28%)
 //  # of combos (10-length) with rules (07 uniques): 227,816,654,691 (21%)
 //  # of combos (10-length) with rules (06 uniques): 67,548,071,052 (6%)
 //  # of combos (10-length) with rules (05 uniques): 7,082,918,186 (0.6%)
 //  # of combos (10-length) with rules (04 uniques): 177,046,022 (0.00016%)

 // ---------------------------------------------------
 // Number of combinations (9-length)
 // ---------------------------------------------------
 //  # of combos (9-length) = 68,719,476,736 (16^9)
 //  # of combos (9-length) with rules = 52,391,215,044 (76%)
 //  # of combos (9-length) with rules (9 uniques): 3,900,662,720 (5.7%)
 //  # of combos (9-length) with rules (8 uniques): 16,389,572,810 (24%)
 //  # of combos (9-length) with rules (7 uniques): 20,700,766,633 (30%)
 //  # of combos (9-length) with rules (6 uniques): 9,691,740,753 (14%)
 //  # of combos (9-length) with rules (5 uniques): 1,630,851,073 (2.4%)
 //  # of combos (9-length) with rules (4 uniques): 77,368,591 (0.1%)
 //  # of combos (9-length) with rules (3 uniques): 252,464 (0.0004%)

 // ---------------------------------------------------
 // Number of combinations (8-length)
 // ---------------------------------------------------
 //  # of combos (8-length) = 4,294,967,296 (16^8)
 //  # of combos (8-length) with rules = 3,304,474,586
 //  # of combos (8-length) with rules (8 uniques): 475,482,556 (77%)
 //  # of combos (8-length) with rules (7 uniques): 1,369,444,939 (32%)
 //  # of combos (8-length) with rules (6 uniques): 1,122,626,680 (26%)
 //  # of combos (8-length) with rules (5 uniques): 310,515,149 (7.2%)
 //  # of combos (8-length) with rules (4 uniques): 26,053,715 (0.6%)
 //  # of combos (8-length) with rules (3 uniques): 351,547 (0.008%)

 // --------------------------------------------------
 // Networks which use hex digits as their default key
 // --------------------------------------------------
 // NETWORK			KEY			COMMAND
 // 3Wireless-Modem-XXXX	8 upper hex		hex -upper -len8 | oclHashcat64 -m 2500 xyz.hccap
 // belkin.xxx 			8 lower hex		hex -len8 | oclHashcat64 -m 2500 xyz.hccap
 // belkin.xxxx 		8 lower hex		hex -len8 | oclHashcat64 -m 2500 xyz.hccap
 // Belkin.XXXX			8 upper hex		hex -upper -len8 | oclHashcat64 -m 2500 xyz.hccap
 // Belkin_XXXXX		8 upper hex		hex -upper -len8 | oclHashcat64 -m 2500 xyz.hccap
 // Belkin_XXXXXX		8 upper hex		hex -upper -len8 | oclHashcat64 -m 2500 xyz.hccap
 // BELLxxx			8 upper hex		hex -upper -len8 | oclHashcat64 -m 2500 xyz.hccap
 // BigPondXXXXXX		10 upper hex		hex -upper | oclHashcat64 -m 2500 xyz.hccap
 // BTHomeHub1XXXX		10 lower hex		hex | oclHashcat64 -m 2500 xyz.hccap
 // BTHomeHub2XXXX		10 lower hex		hex -no01 | oclHashcat64 -m 2500 xyz.hccap
 // BTHomeHub2-XXXX		10 lower hex		hex -no01 | oclHashcat64 -m 2500 xyz.hccap
 // BTHomeHub-XXXX		10 lower hex		hex | oclHashcat64 -m 2500 xyz.hccap
 // BTHub3			10 lower hex		hex -no01 | oclHashcat64 -m 2500 xyz.hccap
 // BTHub4			10 lower hex		hex -no01 | oclHashcat64 -m 2500 xyz.hccap
 // BTHub5			10 lower hex		hex -no01 | oclHashcat64 -m 2500 xyz.hccap
 // CenturyLinkXXXX		14 lower hex		not supported
 // Domino-XXXX			8 upper hex		hex -upper -len8 | oclHashcat64 -m 2500 xyz.hccap
 // E583x-xxxxx			8 upper hex		hex -upper -len8 | oclHashcat64 -m 2500 xyz.hccap
 // EasyBox-XXXXXX		9 upper hex		hex -upper -len9 | oclHashcat64 -m 2500 xyz.hccap
 // MGTS_GPON_XXXX		8 lower hex		hex -len8 | oclHashcat64 -m 2500 xyz.hccap
 // Orange-XXXX			8 upper hex		hex -upper -len8 | oclHashcat64 -m 2500 xyz.hccap
 // PlusnetWireless-XXXXXX	10 upper hex		hex -upper | oclHashcat64 -m 2500 xyz.hccap
 // PRIMEHOME-XX		8 lower hex		hex -len8 | oclHashcat64 -m 2500 xyz.hccap
 // SpeedTouchXXXXXX		10 lower hex		hex | oclHashcat64 -m 2500 xyz.hccap
 // Technicolor/Thomson		10 upper hex		hex -upper | oclHashcat64 -m 2500 xyz.hccap
 // TELUSXXXX			10 lower hex		hex -no01 | oclHashcat64 -m 2500 xyz.hccap
 // TelstraXXXXXX		10 upper hex		hex -upper | oclHashcat64 -m 2500 xyz.hccap
 // TNCAP-XXXX			10 upper hex		hex -upper | oclHashcat64 -m 2500 xyz.hccap
 // TNCAPXXXXXX			10 upper hex		hex -upper | oclHashcat64 -m 2500 xyz.hccap
 // TP-LINK_XXXXXX		8 upper hex		hex -upper -len8 | oclHashcat64 -m 2500 xyz.hccap
 // WLAN1-XXXXXX		10 upper hex		hex -upper | oclHashcat64 -m 2500 xyz.hccap

/*
New potential rules
-does not contain 6+ letters
-does not contain 3+ identical numbers
-does not contain 4+ identical letters
*/

 for (int slot1=slot1_start_at;slot1<slot1_stop_at;slot1++) { // SLOT 1
  possible_chars_freq[0]=possible_chars_freq[1]=possible_chars_freq[2]=possible_chars_freq[3]=possible_chars_freq[4]=possible_chars_freq[5]=possible_chars_freq[6]=possible_chars_freq[7]=possible_chars_freq[8]=possible_chars_freq[9]=possible_chars_freq[10]=possible_chars_freq[11]=possible_chars_freq[12]=possible_chars_freq[13]=possible_chars_freq[14]=possible_chars_freq[15]=0;
  hex_chars[0] = possible_chars[slot1];
  ++possible_chars_freq[slot1];

  for (int slot2=start_at;slot2<possible_chars_length;possible_chars_freq[slot2++]--) { // SLOT 2
   hex_chars[1] = possible_chars[slot2];
   ++possible_chars_freq[slot2];
   if ((slot1==0)&&(slot2==0)) { continue; }                        // does not begin with 00
   if ((slot1==1)&&(slot2==1)) { continue; }                        // does not begin with 11
   if ((slot1==2)&&(slot2==2)) { continue; }                        // does not begin with 22
   if ((slot1==3)&&(slot2==3)) { continue; }                        // does not begin with 33
   if ((slot1==5)&&(slot2==5)) { continue; }                        // does not begin with 55
   if ((slot1==6)&&(slot2==6)) { continue; }                        // does not begin with 66
   if ((slot1==7)&&(slot2==7)) { continue; }                        // does not begin with 77
   if ((slot1==10)&&(slot2==10)) { continue; }                        // does not begin with aa
   if ((slot1==11)&&(slot2==11)) { continue; }                        // does not begin with bb
   if ((slot1==12)&&(slot2==12)) { continue; }                        // does not begin with cc
   if ((slot1==13)&&(slot2==13)) { continue; }                        // does not begin with dd
   if ((slot1==14)&&(slot2==14)) { continue; }                        // does not begin with ee
   if ((slot1==15)&&(slot2==15)) { continue; }                        // does not begin with ff

   for (int slot3=start_at;slot3<possible_chars_length;possible_chars_freq[slot3++]--) { // SLOT 3
    hex_chars[2] = possible_chars[slot3];
    ++possible_chars_freq[slot3];
    if ((slot2==(slot1+1))&&(slot3==(slot2+1))) { continue; }       // no 3 characters in a row can be sequential
    if ((slot3==slot2)&&(slot2==slot1)) { continue; }               // no 3 characters in a row can be identical

    for (int slot4=start_at;slot4<possible_chars_length;possible_chars_freq[slot4++]--) { // SLOT 4
     hex_chars[3] = possible_chars[slot4];
     if (++possible_chars_freq[slot4] > 3) { continue; }            // each character cannot appear more than 3 times
     if ((slot1==slot3)&&(slot2==slot4)) { continue; }              // characters 1 and 3, and 2 and 4 are not identical
     if ((slot1==slot3)&&(slot3==slot4)) { continue; }              // characters 1 and 3 and 4 are not identical      
     if ((slot1==slot3)&&(slot4==(slot2+1))) { continue; }          // when characters 1 and 3 are equal, character 4 is not +1 to character 2
     if ((slot3==(slot2+1))&&(slot4==(slot3+1))) { continue; }      // no 3 characters in a row can be sequential
//     if ((slot4==slot3)&&(slot3==slot2)) { continue; }              // no 3 characters in a row can be identical (disproven)

     for (int slot5=start_at;slot5<possible_chars_length;possible_chars_freq[slot5++]--) { // SLOT 5
      hex_chars[4] = possible_chars[slot5];
      if (++possible_chars_freq[slot5] > 3) { continue; }           // each character cannot appear more than 3 times
      if ((slot4==(slot3+1))&&(slot5==(slot4+1))) { continue; }     // no 3 characters in a row can be sequential
//      if ((slot5==slot4)&&(slot4==slot3)) { continue; }             // no 3 characters in a row can be identical (disproven)

      for (int slot6=start_at;slot6<possible_chars_length;possible_chars_freq[slot6++]--) { // SLOT 6
       hex_chars[5] = possible_chars[slot6];
       if (++possible_chars_freq[slot6] > 3) { continue; }          // each character cannot appear more than 3 times
       if ((slot3==slot5)&&(slot4==slot6)) { continue; }            // characters 3 and 5, and 4 and 6 are not identical
       if ((slot5==(slot4+1))&&(slot6==(slot5+1))) { continue; }    // no 3 characters in a row can be sequential
       if ((slot6==slot5)&&(slot5==slot4)) { continue; }            // no 3 characters in a row can be identical
       if ((possible_chars_freq[10]+possible_chars_freq[11]+possible_chars_freq[12]+possible_chars_freq[13]+possible_chars_freq[14]+possible_chars_freq[15]) >= 9) { continue; } // cannot contain 9+ letters

       for (int slot7=start_at;slot7<possible_chars_length;possible_chars_freq[slot7++]--) { // SLOT 7
        hex_chars[6] = possible_chars[slot7];
        if (++possible_chars_freq[slot7] > 3) { continue; }         // each character cannot appear more than 3 times
        if ((slot6==(slot5+1))&&(slot7==(slot6+1))) { continue; }   // no 3 characters in a row can be sequential
        if ((slot7==slot6)&&(slot6==slot5)) { continue; }           // no 3 characters in a row can be identical
        if ((possible_chars_freq[10]+possible_chars_freq[11]+possible_chars_freq[12]+possible_chars_freq[13]+possible_chars_freq[14]+possible_chars_freq[15]) >= 9) { continue; } // cannot contain 9+ letters

        for (int slot8=start_at;slot8<possible_chars_length;possible_chars_freq[slot8++]--) { // SLOT 8
         hex_chars[7] = possible_chars[slot8];
         if (++possible_chars_freq[slot8] > 3) { continue; }        // each character cannot appear more than 3 times
         if ((slot7==(slot6+1))&&(slot8==(slot7+1))) { continue; }  // no 3 characters in a row can be sequential
         if ((slot8==slot7)&&(slot7==slot6)) { continue; }          // no 3 characters in a row can be identical
         if ((possible_chars_freq[10]+possible_chars_freq[11]+possible_chars_freq[12]+possible_chars_freq[13]+possible_chars_freq[14]+possible_chars_freq[15]) >= 9) { continue; } // cannot contain 9+ letters
//         if ((((slot1>9)?1:0)+((slot2>9)?1:0)+((slot3>9)?1:0)+((slot4>9)?1:0)+((slot5>9)?1:0)+((slot6>9)?1:0)+((slot7>9)?1:0)+((slot8>9)?1:0)) < 2) { continue; } // there must be at least 2 letters in the first 8 characters
         if ((use_len_8) && (use_len_9==false)) {
          if ((odd_only)&&(slot8%2==0)) { continue; }
          if ((even_only)&&(slot8%2!=0)) { continue; }
          if ((slot2==slot3)&&(slot3==slot8)) { continue; } // characters 2, 3 and 8 cannot be identical (8-len)
          if ((possible_chars_freq[0]+possible_chars_freq[1]+possible_chars_freq[2]+possible_chars_freq[3]+possible_chars_freq[4]+possible_chars_freq[5]+possible_chars_freq[6]+possible_chars_freq[7]+possible_chars_freq[8]+possible_chars_freq[9]) >= 7) { continue; } // cannot contain 7+ numbers
          unique_count = ((possible_chars_freq[0]!=0)?1:0) + ((possible_chars_freq[1]!=0)?1:0) + ((possible_chars_freq[2]!=0)?1:0) + ((possible_chars_freq[3]!=0)?1:0) + ((possible_chars_freq[4]!=0)?1:0) + ((possible_chars_freq[5]!=0)?1:0) + ((possible_chars_freq[6]!=0)?1:0) + ((possible_chars_freq[7]!=0)?1:0) + ((possible_chars_freq[8]!=0)?1:0) + ((possible_chars_freq[9]!=0)?1:0) + ((possible_chars_freq[10]!=0)?1:0) + ((possible_chars_freq[11]!=0)?1:0) + ((possible_chars_freq[12]!=0)?1:0) + ((possible_chars_freq[13]!=0)?1:0) + ((possible_chars_freq[14]!=0)?1:0) + ((possible_chars_freq[15]!=0)?1:0);
          if ((desired_uniques == 0) || ((desired_uniques != 0) && (desired_uniques == unique_count))) {
           std::cout << hex_chars[0] << hex_chars[1] << hex_chars[2] << hex_chars[3] << hex_chars[4] << hex_chars[5] << hex_chars[6] << hex_chars[7] << std::endl;
          }
         }

         for (int slot9=start_at;slot9<possible_chars_length;possible_chars_freq[slot9++]--) { // SLOT 9
          if (use_len_8) { break; }
          hex_chars[8] = possible_chars[slot9];
          if (++possible_chars_freq[slot9] > 3) { continue; }       // each character cannot appear more than 3 times
          if ((slot8==(slot7+1))&&(slot9==(slot8+1))) { continue; } // no 3 characters in a row can be sequential
          if ((slot9==slot8)&&(slot8==slot7)) { continue; }         // no 3 characters in a row can be identical
          if ((possible_chars_freq[10]+possible_chars_freq[11]+possible_chars_freq[12]+possible_chars_freq[13]+possible_chars_freq[14]+possible_chars_freq[15]) >= 9) { continue; } // cannot contain 9+ letters
          if (use_len_9)  {
           if ((odd_only)&&(slot9%2==0)) { continue; }
           if ((even_only)&&(slot9%2!=0)) { continue; }
           if ((slot2==slot3)&&(slot3==slot9)) { continue; } // characters 2, 3 and 9 cannot be identical (9-len)
           if ((possible_chars_freq[0]+possible_chars_freq[1]+possible_chars_freq[2]+possible_chars_freq[3]+possible_chars_freq[4]+possible_chars_freq[5]+possible_chars_freq[6]+possible_chars_freq[7]+possible_chars_freq[8]+possible_chars_freq[9]) >= 8) { continue; } // cannot contain 8+ numbers
           unique_count = ((possible_chars_freq[0]!=0)?1:0) + ((possible_chars_freq[1]!=0)?1:0) + ((possible_chars_freq[2]!=0)?1:0) + ((possible_chars_freq[3]!=0)?1:0) + ((possible_chars_freq[4]!=0)?1:0) + ((possible_chars_freq[5]!=0)?1:0) + ((possible_chars_freq[6]!=0)?1:0) + ((possible_chars_freq[7]!=0)?1:0) + ((possible_chars_freq[8]!=0)?1:0) + ((possible_chars_freq[9]!=0)?1:0) + ((possible_chars_freq[10]!=0)?1:0) + ((possible_chars_freq[11]!=0)?1:0) + ((possible_chars_freq[12]!=0)?1:0) + ((possible_chars_freq[13]!=0)?1:0) + ((possible_chars_freq[14]!=0)?1:0) + ((possible_chars_freq[15]!=0)?1:0);
           if ((desired_uniques == 0) || ((desired_uniques != 0) && (desired_uniques == unique_count))) {
            std::cout << hex_chars[0] << hex_chars[1] << hex_chars[2] << hex_chars[3] << hex_chars[4] << hex_chars[5] << hex_chars[6] << hex_chars[7] << hex_chars[8] << std::endl;
           }
          }

          for (int slot10=start_at;slot10<possible_chars_length;possible_chars_freq[slot10++]--) { // SLOT 10
           if ((use_len_8) || (use_len_9)) { break; }
           hex_chars[9] = possible_chars[slot10];
           if (++possible_chars_freq[slot10] > 3) { continue; }       // each character cannot appear more than 3 times
           if ((odd_only)&&(slot10%2==0)) { continue; }
           if ((even_only)&&(slot10%2!=0)) { continue; }
           if ((slot2==slot3)&&(slot3==slot10)) { continue; }         // characters 2, 3 and 10 cannot be identical
           if ((slot9==(slot8+1))&&(slot10==(slot9+1))) { continue; } // no 3 characters in a row can be sequential
           //if ((slot10==slot9)&&(slot9==slot8)) { continue; }         // no 3 characters in a row can be identical (disproven)
           if ((possible_chars_freq[10]+possible_chars_freq[11]+possible_chars_freq[12]+possible_chars_freq[13]+possible_chars_freq[14]+possible_chars_freq[15]) >= 9) { continue; } // cannot contain 9+ letters
           if ((possible_chars_freq[0]+possible_chars_freq[1]+possible_chars_freq[2]+possible_chars_freq[3]+possible_chars_freq[4]+possible_chars_freq[5]+possible_chars_freq[6]+possible_chars_freq[7]+possible_chars_freq[8]+possible_chars_freq[9]) >= 9) { continue; } // cannot contain 9+ numbers

           unique_count = ((possible_chars_freq[0]!=0)?1:0) + ((possible_chars_freq[1]!=0)?1:0) + ((possible_chars_freq[2]!=0)?1:0) + ((possible_chars_freq[3]!=0)?1:0) + ((possible_chars_freq[4]!=0)?1:0) + ((possible_chars_freq[5]!=0)?1:0) + ((possible_chars_freq[6]!=0)?1:0) + ((possible_chars_freq[7]!=0)?1:0) + ((possible_chars_freq[8]!=0)?1:0) + ((possible_chars_freq[9]!=0)?1:0) + ((possible_chars_freq[10]!=0)?1:0) + ((possible_chars_freq[11]!=0)?1:0) + ((possible_chars_freq[12]!=0)?1:0) + ((possible_chars_freq[13]!=0)?1:0) + ((possible_chars_freq[14]!=0)?1:0) + ((possible_chars_freq[15]!=0)?1:0);

           //++counter;
           //++uniques_counter[unique_count-1];

           if (((desired_uniques==0)&&(min_uniques==0)) || (desired_uniques==unique_count) || ((desired_uniques==0)&&(min_uniques>0)&&(unique_count>=min_uniques)&&(unique_count<=max_uniques))) {
            ++counter;
            if (counter >= start_at_long) {
             if ((stop_at_long > 0) && (counter >= stop_at_long)) { return 0; }
              std::cout << hex_chars[0] << hex_chars[1] << hex_chars[2] << hex_chars[3] << hex_chars[4] << hex_chars[5] << hex_chars[6] << hex_chars[7] << hex_chars[8] << hex_chars[9] << std::endl;
            }
           }

          }
         }
        }
       }
      }
     }
    }
   }
  }
 }


 }

/*
// debugging info
 std::cout << "counter: " << counter << std::endl;
 std::cout << "uniques_counter[0]: " << uniques_counter[0] << std::endl;
 std::cout << "uniques_counter[1]: " << uniques_counter[1] << std::endl;
 std::cout << "uniques_counter[2]: " << uniques_counter[2] << std::endl;
 std::cout << "uniques_counter[3]: " << uniques_counter[3] << std::endl;
 std::cout << "uniques_counter[4]: " << uniques_counter[4] << std::endl;
 std::cout << "uniques_counter[5]: " << uniques_counter[5] << std::endl;
 std::cout << "uniques_counter[6]: " << uniques_counter[6] << std::endl;
 std::cout << "uniques_counter[7]: " << uniques_counter[7] << std::endl;
 std::cout << "uniques_counter[8]: " << uniques_counter[8] << std::endl;
 std::cout << "uniques_counter[9]: " << uniques_counter[9] << std::endl;
*/

 return 0;
}