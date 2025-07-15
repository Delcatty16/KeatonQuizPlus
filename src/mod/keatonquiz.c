#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "eztr_api.h"
#include "overlays/actors/ovl_En_Kitan/z_en_kitan.h"

//RECOMP_PATCH u16 EnKitan_GetQuestionMessageId(EnKitan* this) {
    // always return the "romani balloon" question
//    return 0x4B6;
//}
//RECOMP_PATCH u16 EnKitan_GetQuestionMessageId(EnKitan* this) {
    // always return the "romani weapon" question
//    return 0x4B8;
//}
//RECOMP_PATCH u16 EnKitan_GetQuestionMessageId(EnKitan* this) {
//    // always return the "romani bedtime" question
//    return 0x4BA;
//}

EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion0);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer0);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion1);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer1);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion2);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer2);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion3);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer3);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion4);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer4);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion5);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer5);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion6);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer6);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion7);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer7);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion8);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer8);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion9);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer9);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion10);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer10);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion11);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer11);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion12);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer12);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion13);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer13);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion14);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer14);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion15);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer15);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion16);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer16);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion17);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer17);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion18);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer18);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion19);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer19);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion20);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer20);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion21);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer21);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion22);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer22);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion23);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer23);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion24);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer24);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion25);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer25);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion26);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer26);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion27);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer27);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion28);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer28);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomQuestion29);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(CustomAnswer29);

u16 CustomMsgID[60] = {0};

RECOMP_PATCH u16 EnKitan_GetQuestionMessageId(EnKitan* this) {
    s32 i = 0;

    while (true) {
        s32 rand = Rand_ZeroFloat(14.0f);

        // Keep track of which questions have already been asked with a bitset
        if (!(this->textBitSet & (1 << rand))) {
            this->textBitSet |= 1 << rand;
            // 0x04B6 is the start of the question + answer choice textboxes, each question textbox is followed by the
            // choice textbox containing the answer choices
            return CustomMsgID[rand * 2];
        }

        i++;
        if (i > 1000) {
            // There's an assert(false) here in the debug version to catch any unforeseen issues in testing. It is
            // assumed that if this function is called there is always at least one question available to be selected.
        }
    }
}

//RECOMP_HOOK("EnKitan_Appear")


RECOMP_HOOK("EnKitan_Talk")
void EnKitanQuizLength(EnKitan* this, PlayState* play) {
    switch (Message_GetState(&play->msgCtx)) {
        case TEXT_STATE_CHOICE:
            if (!Message_ShouldAdvance(play)) {
                break;
            }

            if ((play->msgCtx.choiceIndex + 1) == play->msgCtx.unk1206C) {
                // Correct answer, continue quiz or end if enough questions have been answered correctly
                Audio_PlaySfx(NA_SE_SY_QUIZ_CORRECT);

                // Here the timer is being used as a counter for number of correct answers
                this->timer++;
                if (this->timer < recomp_get_config_u32("KeatonQuizNumber")) {
                    play->msgCtx.msgLength = 0;
                } else {
                    // Enough questions have been answered, continue to prize
                    this->timer = 0;
                    this->textBitSet = 0;
                    Message_ContinueTextbox(play, 0x04B4);
                }
                Animation_MorphToPlayOnce(&this->skelAnime, &gKeatonCelebrateAnim, -5.0f);
            } else {
                // Wrong answer, end quiz
                Audio_PlaySfx(NA_SE_SY_QUIZ_INCORRECT);
                Animation_MorphToLoop(&this->skelAnime, &gKeatonChuckleAnim, -5.0f);
                Message_ContinueTextbox(play, 0x04B3);
                this->timer = 0;
                this->textBitSet = 0;
            }
                        break;
        
        case TEXT_STATE_EVENT:
            if (!Message_ShouldAdvance(play)) {
                break;
            }
                //Makes the text box able to advance, even when the Message ID is odd.
            if ((play->msgCtx.currentTextId & 1)) {
                Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
            }
            
            break;
    
    }
}
EZTR_ON_INIT void init_text() {
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion0),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "In Ikana, how many " EZTR_CC_COLOR_RED "Gibdo" EZTR_CC_COLOR_DEFAULT " are " EZTR_CC_COLOR_RED "" EZTR_CC_NEWLINE "Beneath the Well" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer0),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Thirteen" EZTR_CC_NEWLINE "Ten" EZTR_CC_NEWLINE "Twelve" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion1),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Throughout all of " EZTR_CC_COLOR_RED "Termina" EZTR_CC_COLOR_DEFAULT "," EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "where can you find the " EZTR_CC_COLOR_RED "Poe " EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "enemy?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer1),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Ikana Graveyard" EZTR_CC_NEWLINE "Stone Tower Temple" EZTR_CC_NEWLINE "Beneath the Well" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion2),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Why won't the " EZTR_CC_COLOR_RED "Postman" EZTR_CC_COLOR_DEFAULT " flee?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer2),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "He doesn't have a place to hide" EZTR_CC_NEWLINE "He thinks the moon will not fall" EZTR_CC_NEWLINE "It's not in his schedule" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion3),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " EZTR_CC_COLOR_RED "Great Fairies" EZTR_CC_COLOR_DEFAULT " are in " EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "Termina"  EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer3),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Three" EZTR_CC_NEWLINE "Four" EZTR_CC_NEWLINE "Five" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion4),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What " EZTR_CC_COLOR_RED "animal" EZTR_CC_COLOR_DEFAULT " is on the back of" EZTR_CC_NEWLINE "Anju's" EZTR_CC_COLOR_RED " Grandmother's" EZTR_CC_COLOR_DEFAULT " wheelchair?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer4),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Lion" EZTR_CC_NEWLINE "Tiger" EZTR_CC_NEWLINE "Cheetah" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion5),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "We " EZTR_CC_COLOR_RED "Keaton" EZTR_CC_COLOR_DEFAULT " will appear in" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "North Clock Town " EZTR_CC_COLOR_DEFAULT "and " EZTR_CC_COLOR_RED "Milk Road" EZTR_CC_COLOR_DEFAULT"." EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "Where else" EZTR_CC_COLOR_DEFAULT" can we appear?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer5),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Mountain Village" EZTR_CC_NEWLINE "Zora Cape" EZTR_CC_NEWLINE "Road to Ikana" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion6),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What " EZTR_CC_COLOR_RED "instrument" EZTR_CC_COLOR_DEFAULT " does " EZTR_CC_COLOR_RED "Evan " EZTR_CC_COLOR_DEFAULT "of the" EZTR_CC_NEWLINE "Zora band, " EZTR_CC_COLOR_RED "The Indigo-Go's" EZTR_CC_COLOR_DEFAULT" play?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer6),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Drums" EZTR_CC_NEWLINE "Guitar" EZTR_CC_NEWLINE "Piano" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion7),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " EZTR_CC_COLOR_RED "name" EZTR_CC_COLOR_DEFAULT " of the " EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "King of Ikana" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer7),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Daphnes Nohansen Ikana" EZTR_CC_NEWLINE "Igos du Ikana" EZTR_CC_NEWLINE "Rhoam Bosphoramus Ikana" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion8),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " EZTR_CC_COLOR_RED "weapon" EZTR_CC_COLOR_DEFAULT " of choice for " EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "Gomess" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer8),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Scythe" EZTR_CC_NEWLINE "Sword and shield" EZTR_CC_NEWLINE "Battle-axe" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion9),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " EZTR_CC_COLOR_RED "weapon" EZTR_CC_COLOR_DEFAULT " of choice for " EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "Odolwa" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer9),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Scythe" EZTR_CC_NEWLINE "Sword and shield" EZTR_CC_NEWLINE "Battle-axe" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion10),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who has the " EZTR_CC_COLOR_RED "title" EZTR_CC_COLOR_DEFAULT " of " EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "Masked Mechanical Monster" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer10),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Goht" EZTR_CC_NEWLINE "Gyorg" EZTR_CC_NEWLINE "Twinmold" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion11),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who has the " EZTR_CC_COLOR_RED "title" EZTR_CC_COLOR_DEFAULT " of " EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "Gargantuan Masked Fish" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer11),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Goht" EZTR_CC_NEWLINE "Gyorg" EZTR_CC_NEWLINE "Twinmold" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion12),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who has the " EZTR_CC_COLOR_RED "title" EZTR_CC_COLOR_DEFAULT " of " EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "Giant Masked Insect" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer12),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Goht" EZTR_CC_NEWLINE "Gyorg" EZTR_CC_NEWLINE "Twinmold" EZTR_CC_END "",
        NULL
    );
        EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion13),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " EZTR_CC_COLOR_RED "song" EZTR_CC_NEWLINE "Toto" EZTR_CC_COLOR_DEFAULT " of the Zora asks you to " EZTR_CC_NEWLINE "play in the " EZTR_CC_COLOR_RED "Milk Bar" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer13),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Ballad of the Sea" EZTR_CC_NEWLINE "Ballad of the Wind Fish" EZTR_CC_NEWLINE "Ballad of the Goddess" EZTR_CC_END "",
        NULL
    );
    CustomMsgID[0] = EZTR_GET_ID_H(CustomQuestion0);
    CustomMsgID[1] = EZTR_GET_ID_H(CustomAnswer0);
    CustomMsgID[2] = EZTR_GET_ID_H(CustomQuestion1);
    CustomMsgID[3] = EZTR_GET_ID_H(CustomAnswer1);
    CustomMsgID[4] = EZTR_GET_ID_H(CustomQuestion2);
    CustomMsgID[5] = EZTR_GET_ID_H(CustomAnswer2);
    CustomMsgID[6] = EZTR_GET_ID_H(CustomQuestion3);
    CustomMsgID[7] = EZTR_GET_ID_H(CustomAnswer3);
    CustomMsgID[8] = EZTR_GET_ID_H(CustomQuestion4);
    CustomMsgID[9] = EZTR_GET_ID_H(CustomAnswer4);
    CustomMsgID[10] = EZTR_GET_ID_H(CustomQuestion5);
    CustomMsgID[11] = EZTR_GET_ID_H(CustomAnswer5);
    CustomMsgID[12] = EZTR_GET_ID_H(CustomQuestion6);
    CustomMsgID[13] = EZTR_GET_ID_H(CustomAnswer6);
    CustomMsgID[14] = EZTR_GET_ID_H(CustomQuestion7);
    CustomMsgID[15] = EZTR_GET_ID_H(CustomAnswer7);
    CustomMsgID[16] = EZTR_GET_ID_H(CustomQuestion8);
    CustomMsgID[17] = EZTR_GET_ID_H(CustomAnswer8);
    CustomMsgID[18] = EZTR_GET_ID_H(CustomQuestion9);
    CustomMsgID[19] = EZTR_GET_ID_H(CustomAnswer9);
    CustomMsgID[20] = EZTR_GET_ID_H(CustomQuestion10);
    CustomMsgID[21] = EZTR_GET_ID_H(CustomAnswer10);
    CustomMsgID[22] = EZTR_GET_ID_H(CustomQuestion11);
    CustomMsgID[23] = EZTR_GET_ID_H(CustomAnswer11);
    CustomMsgID[24] = EZTR_GET_ID_H(CustomQuestion12);
    CustomMsgID[25] = EZTR_GET_ID_H(CustomAnswer12);
    CustomMsgID[26] = EZTR_GET_ID_H(CustomQuestion13);
    CustomMsgID[27] = EZTR_GET_ID_H(CustomAnswer13);
    // CustomMsgID[28] = EZTR_GET_ID_H(CustomQuestion14);
    // CustomMsgID[29] = EZTR_GET_ID_H(CustomAnswer14);
    // CustomMsgID[30] = EZTR_GET_ID_H(CustomQuestion15);
    // CustomMsgID[31] = EZTR_GET_ID_H(CustomAnswer15);
    // CustomMsgID[32] = EZTR_GET_ID_H(CustomQuestion16);
    // CustomMsgID[33] = EZTR_GET_ID_H(CustomAnswer16);
    // CustomMsgID[34] = EZTR_GET_ID_H(CustomQuestion17);
    // CustomMsgID[35] = EZTR_GET_ID_H(CustomAnswer17);
    // CustomMsgID[36] = EZTR_GET_ID_H(CustomQuestion18);
    // CustomMsgID[37] = EZTR_GET_ID_H(CustomAnswer18);
    // CustomMsgID[38] = EZTR_GET_ID_H(CustomQuestion19);
    // CustomMsgID[39] = EZTR_GET_ID_H(CustomAnswer19);
    // CustomMsgID[40] = EZTR_GET_ID_H(CustomQuestion20);
    // CustomMsgID[41] = EZTR_GET_ID_H(CustomAnswer20);
    // CustomMsgID[42] = EZTR_GET_ID_H(CustomQuestion21);
    // CustomMsgID[43] = EZTR_GET_ID_H(CustomAnswer21);
    // CustomMsgID[44] = EZTR_GET_ID_H(CustomQuestion22);
    // CustomMsgID[45] = EZTR_GET_ID_H(CustomAnswer22);
    // CustomMsgID[46] = EZTR_GET_ID_H(CustomQuestion23);
    // CustomMsgID[47] = EZTR_GET_ID_H(CustomAnswer23);
    // CustomMsgID[48] = EZTR_GET_ID_H(CustomQuestion24);
    // CustomMsgID[49] = EZTR_GET_ID_H(CustomAnswer24);
    // CustomMsgID[50] = EZTR_GET_ID_H(CustomQuestion25);
    // CustomMsgID[51] = EZTR_GET_ID_H(CustomAnswer25);
    // CustomMsgID[52] = EZTR_GET_ID_H(CustomQuestion26);
    // CustomMsgID[53] = EZTR_GET_ID_H(CustomAnswer26);
    // CustomMsgID[54] = EZTR_GET_ID_H(CustomQuestion27);
    // CustomMsgID[55] = EZTR_GET_ID_H(CustomAnswer27);
    // CustomMsgID[56] = EZTR_GET_ID_H(CustomQuestion28);
    // CustomMsgID[57] = EZTR_GET_ID_H(CustomAnswer28);
    // CustomMsgID[58] = EZTR_GET_ID_H(CustomQuestion29);
    // CustomMsgID[59] = EZTR_GET_ID_H(CustomAnswer29);
}