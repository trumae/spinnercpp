#ifndef __SPINNERCPP__
#define __SPINNERCPP__

#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

namespace spinnercpp {
  using namespace std;

  vector<vector<string>> CharSets = {
    {"←", "↖", "↑", "↗", "→", "↘", "↓", "↙"},
    {"▁", "▃", "▄", "▅", "▆", "▇", "█", "▇", "▆", "▅", "▄", "▃", "▁"},
    {"▖", "▘", "▝", "▗"},
    {"┤", "┘", "┴", "└", "├", "┌", "┬", "┐"},
    {"◢", "◣", "◤", "◥"},
    {"◰", "◳", "◲", "◱"},
    {"◴", "◷", "◶", "◵"},
    {"◐", "◓", "◑", "◒"},
    {".", "o", "O", "@", "*"},
    {"|", "/", "-", "\\"},
    {"◡◡", "⊙⊙", "◠◠"},
    {"⣾", "⣽", "⣻", "⢿", "⡿", "⣟", "⣯", "⣷"},
    {">))'>", " >))'>", "  >))'>", "   >))'>", "    >))'>", "   <'((<", "  <'((<", " <'((<"},
    {"⠁", "⠂", "⠄", "⡀", "⢀", "⠠", "⠐", "⠈"},
    {"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"},
    {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"},
    {"▉", "▊", "▋", "▌", "▍", "▎", "▏", "▎", "▍", "▌", "▋", "▊", "▉"},
    {"■", "□", "▪", "▫"},
    {"←", "↑", "→", "↓"},
    {"╫", "╪"},
    {"⇐", "⇖", "⇑", "⇗", "⇒", "⇘", "⇓", "⇙"},
    {"⠁", "⠁", "⠉", "⠙", "⠚", "⠒", "⠂", "⠂", "⠒", "⠲", "⠴", "⠤", "⠄", "⠄", "⠤", "⠠", "⠠", "⠤", "⠦", "⠖", "⠒", "⠐", "⠐", "⠒", "⠓", "⠋", "⠉", "⠈", "⠈"},
    {"⠈", "⠉", "⠋", "⠓", "⠒", "⠐", "⠐", "⠒", "⠖", "⠦", "⠤", "⠠", "⠠", "⠤", "⠦", "⠖", "⠒", "⠐", "⠐", "⠒", "⠓", "⠋", "⠉", "⠈"},
    {"⠁", "⠉", "⠙", "⠚", "⠒", "⠂", "⠂", "⠒", "⠲", "⠴", "⠤", "⠄", "⠄", "⠤", "⠴", "⠲", "⠒", "⠂", "⠂", "⠒", "⠚", "⠙", "⠉", "⠁"},
    {"⠋", "⠙", "⠚", "⠒", "⠂", "⠂", "⠒", "⠲", "⠴", "⠦", "⠖", "⠒", "⠐", "⠐", "⠒", "⠓", "⠋"},
    {"ｦ", "ｧ", "ｨ", "ｩ", "ｪ", "ｫ", "ｬ", "ｭ", "ｮ", "ｯ", "ｱ", "ｲ", "ｳ", "ｴ", "ｵ", "ｶ", "ｷ", "ｸ", "ｹ", "ｺ", "ｻ", "ｼ", "ｽ", "ｾ", "ｿ", "ﾀ", "ﾁ", "ﾂ", "ﾃ", "ﾄ", "ﾅ", "ﾆ", "ﾇ", "ﾈ", "ﾉ", "ﾊ", "ﾋ", "ﾌ", "ﾍ", "ﾎ", "ﾏ", "ﾐ", "ﾑ", "ﾒ", "ﾓ", "ﾔ", "ﾕ", "ﾖ", "ﾗ", "ﾘ", "ﾙ", "ﾚ", "ﾛ", "ﾜ", "ﾝ"},
    {".", "..", "..."},
    {"▁", "▂", "▃", "▄", "▅", "▆", "▇", "█", "▉", "▊", "▋", "▌", "▍", "▎", "▏", "▏", "▎", "▍", "▌", "▋", "▊", "▉", "█", "▇", "▆", "▅", "▄", "▃", "▂", "▁"},
    {".", "o", "O", "°", "O", "o", "."},
    {"+", "x"},
    {"v", "<", "^", ">"},
    {">>--->", " >>--->", "  >>--->", "   >>--->", "    >>--->", "    <---<<", "   <---<<", "  <---<<", " <---<<", "<---<<"},
    {"|", "||", "|||", "||||", "|||||", "|||||||", "||||||||", "|||||||", "||||||", "|||||", "||||", "|||", "||", "|"},
    {"[          ]", "[=         ]", "[==        ]", "[===       ]", "[====      ]", "[=====     ]", "[======    ]", "[=======   ]", "[========  ]", "[========= ]", "[==========]"},
    {"(*---------)", "(-*--------)", "(--*-------)", "(---*------)", "(----*-----)", "(-----*----)", "(------*---)", "(-------*--)", "(--------*-)", "(---------*)"},
    {"█▒▒▒▒▒▒▒▒▒", "███▒▒▒▒▒▒▒", "█████▒▒▒▒▒", "███████▒▒▒", "██████████"},
    {"[                    ]", "[=>                  ]", "[===>                ]", "[=====>              ]", "[======>             ]", "[========>           ]", "[==========>         ]", "[============>       ]", "[==============>     ]", "[================>   ]", "[==================> ]", "[===================>]"},
    {"🌍", "🌎", "🌏"},
    {"◜", "◝", "◞", "◟"},
    {"⬒", "⬔", "⬓", "⬕"},
    {"⬖", "⬘", "⬗", "⬙"},
    {"[>>>          >]", "[]>>>>        []", "[]  >>>>      []", "[]    >>>>    []", "[]      >>>>  []", "[]        >>>>[]", "[>>          >>]"},
    {"♠", "♣", "♥", "♦"},
    {"➞", "➟", "➠", "➡", "➠", "➟"},
    {"  . . . .", ".   . . .", ". .   . .", ". . .   .", ". . . .  ", ". . . . ."},
    {"⎺", "⎻", "⎼", "⎽", "⎼", "⎻"},
    {"▹▹▹▹▹", "▸▹▹▹▹", "▹▸▹▹▹", "▹▹▸▹▹", "▹▹▹▸▹", "▹▹▹▹▸"},
    {"[    ]", "[   =]", "[  ==]", "[ ===]", "[====]", "[=== ]", "[==  ]", "[=   ]"},
    {"( ●    )", "(  ●   )", "(   ●  )", "(    ● )", "(     ●)", "(    ● )", "(   ●  )", "(  ●   )", "( ●    )"},
    {"✶", "✸", "✹", "✺", "✹", "✷"},
    {"▐|\\____________▌", "▐_|\\___________▌", "▐__|\\__________▌", "▐___|\\_________▌", "▐____|\\________▌", "▐_____|\\_______▌", "▐______|\\______▌", "▐_______|\\_____▌", "▐________|\\____▌", "▐_________|\\___▌", "▐__________|\\__▌", "▐___________|\\_▌", "▐____________|\\▌", "▐____________/|▌", "▐___________/|_▌", "▐__________/|__▌", "▐_________/|___▌", "▐________/|____▌", "▐_______/|_____▌", "▐______/|______▌", "▐_____/|_______▌", "▐____/|________▌", "▐___/|_________▌", "▐__/|__________▌", "▐_/|___________▌", "▐/|____________▌"},
    {"▐⠂       ▌", "▐⠈       ▌", "▐ ⠂      ▌", "▐ ⠠      ▌", "▐  ⡀     ▌", "▐  ⠠     ▌", "▐   ⠂    ▌", "▐   ⠈    ▌", "▐    ⠂   ▌", "▐    ⠠   ▌", "▐     ⡀  ▌", "▐     ⠠  ▌", "▐      ⠂ ▌", "▐      ⠈ ▌", "▐       ⠂▌", "▐       ⠠▌", "▐       ⡀▌", "▐      ⠠ ▌", "▐      ⠂ ▌", "▐     ⠈  ▌", "▐     ⠂  ▌", "▐    ⠠   ▌", "▐    ⡀   ▌", "▐   ⠠    ▌", "▐   ⠂    ▌", "▐  ⠈     ▌", "▐  ⠂     ▌", "▐ ⠠      ▌", "▐ ⡀      ▌", "▐⠠       ▌"},
    {"¿", "?"},
    {"⢹", "⢺", "⢼", "⣸", "⣇", "⡧", "⡗", "⡏"},
    {"⢄", "⢂", "⢁", "⡁", "⡈", "⡐", "⡠"},
    {".  ", ".. ", "...", " ..", "  .", "   "},
    {".", "o", "O", "°", "O", "o", "."},
    {"▓", "▒", "░"},
    {"▌", "▀", "▐", "▄"},
    {"⊶", "⊷"},
    {"▪", "▫"},
    {"□", "■"},
    {"▮", "▯"},
    {"-", "=", "≡"},
    {"d", "q", "p", "b"},
    {"∙∙∙", "●∙∙", "∙●∙", "∙∙●", "∙∙∙"},
    {"🌑 ", "🌒 ", "🌓 ", "🌔 ", "🌕 ", "🌖 ", "🌗 ", "🌘 "},
    {"☗", "☖"},
    {"⧇", "⧆"},
    {"◉", "◎"},
    {"㊂", "㊀", "㊁"},
    {"⦾", "⦿"},
    {"ဝ", "၀"},
    {"▌", "▀", "▐▄"},
  };

  class spinner {
  public:
  spinner(chrono::duration<int,std::milli> delay=200ms,
	  int charset = 0,
	  string finalmsg = "",
	  string prefix = "",
	  string suffix = ""
	  ) : delay_(delay),
      chars_(charset),
      finalmsg_(finalmsg),
      prefix_(prefix),
      suffix_(suffix),
      active_(false) {				
    }

    ~spinner() {
      stop();
    }

    virtual void start() {
      active_ = true;
      
      cout << "\e[?25l";
      cout.flush();
      
      thr_ = thread([&](){
	  int c = -1;
	  auto chars = CharSets[chars_];
	  int l = CharSets[chars_].size();
	  
	  while (active_)  {
	    cout << "\r" << prefix_ << chars[c = ++c % l] << suffix_;
	    cout.flush();
	    std::this_thread::sleep_for(delay_);
	  }
	});
    }
    
    virtual void stop() {
      if (active_) {	
	active_ = false;
	thr_.join();
	cout << "\e[?25h";
	if(finalmsg_.size() > 0 )
	  cout << " - " << finalmsg_ << endl;
	cout.flush();	
      }
    }

  private:
    chrono::duration<int,std::milli> delay_;
    string prefix_;
    string suffix_;
    int chars_;
    string finalmsg_;
    bool active_;
    mutex lock_;
    thread thr_;
  };
}

#endif

