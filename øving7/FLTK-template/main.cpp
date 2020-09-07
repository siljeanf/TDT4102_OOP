#include "Simple_window.h"

#include "Emoji.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
    using namespace Graph_lib;
    
    const Point tl{100, 100};
    const string win_label{"Emoji factory"}; //navn på vindu
    Simple_window win{tl, xmax, ymax, win_label}; //lager et vindu som kalles win
    
    /* TODO:
     *  - initialize emojis
     *  - connect emojis to window
     **/
    
    const Point ef{100,100};
    const Point sf{250,100};
    const Point lf{400,100};
    const Point hf{550,100};
    const Point ft{700,100};
    const Point ic{850,100};
    
    //EmptyFace empf{ ef ,emojiRadius}; //initialiserer emojien emptyface kalt empf
    
    //empf.attach_to(win); //kobler emptyface til vinduet
    
    
    SmilingFace smiley{ef, emojiRadius};
    smiley.attach_to(win);
    
    
    WonderFace sadf{sf, emojiRadius};
    sadf.attach_to(win);
    
    WtfFace wtf{lf, emojiRadius};
    wtf.attach_to(win);
    
    
    CryingFace crt{hf, emojiRadius};
    crt.attach_to(win);
    
    LoveFace love{ft, emojiRadius};
    love.attach_to(win);
    
    EmojiIncest ins{ic, emojiRadius};
    ins.attach_to(win);
    
    win.wait_for_button();
    
}
