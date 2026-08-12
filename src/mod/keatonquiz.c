#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "eztr_api.h"
#include "overlays/actors/ovl_En_Kitan/z_en_kitan.h"
#include "overlays/actors/ovl_En_Kusa2/z_en_kusa2.h"
#include "z64actor.h"
#include "attributes.h"
#define VARIABLE_TEXT_COLOR "\xff"

EZTR_MSG_CALLBACK(quiz_color_changer) {
    char* p = buf->data.content;
    
    for (u8* p = buf->data.content; *p != 0xBF; p++) {
        recomp_printf("Reading %i\n", *p);
        if (*p == 0xFF) {
            recomp_printf("Replacing %i with %i\n", *p, (u8) recomp_get_config_u32("HighlightColour"));
            *p = (u8) recomp_get_config_u32("HighlightColour");
        }
    }
}

void kitanSendDeath() {
    gSaveContext.save.saveInfo.playerData.health = 0;
}

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
enum QuestionSetOptions {
    QUESTION_SET_VANILLA,   // 0
    QUESTION_SET_CUSTOM,    // 1
    QUESTION_SET_OOT,       // 2
    QUESTION_SET_PICTURES,  // 3
};
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
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion0);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer0);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion1);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer1);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion2);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer2);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion3);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer3);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion4);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer4);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion5);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer5);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion6);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer6);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion7);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer7);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion8);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer8);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion9);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer9);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion10);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer10);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion11);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer11);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion12);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer12);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion13);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer13);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion14);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer14);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion15);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer15);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion16);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer16);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion17);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer17);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion18);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer18);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion19);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer19);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion20);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer20);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion21);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer21);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion22);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer22);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion23);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer23);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion24);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer24);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion25);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer25);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion26);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer26);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion27);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer27);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion28);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer28);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTQuestion29);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(OoTAnswer29);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion0);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer0);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion1);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer1);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion2);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer2);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion3);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer3);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion4);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer4);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion5);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer5);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion6);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer6);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion7);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer7);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion8);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer8);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion9);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer9);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion10);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer10);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion11);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer11);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion12);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer12);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion13);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer13);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion14);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer14);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion15);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer15);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion16);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer16);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion17);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer17);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion18);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer18);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion19);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer19);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion20);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer20);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion21);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer21);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion22);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer22);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion23);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer23);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion24);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer24);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion25);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer25);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion26);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer26);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion27);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer27);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion28);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer28);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesQuestion29);
EZTR_DEFINE_CUSTOM_MSG_HANDLE(PicturesAnswer29);

u16 CustomMsgID[60] = {0};
u16 VanillaMsgID[60] ={0x04B6, 0x04B7, 0x04B8, 0x04B9, 0x04BA, 0x04BB, 0x04BC, 0x04BD, 0x04BE, 0x04BF, 0x04C0, 0x04C1, 0x04C2, 0x04C3, 0x04C4, 0x04C5, 0x04C6, 0x04C7, 0x04C8, 0x04C9, 0x04CA, 0x04CB, 0x04CC, 0x04CD, 0x04CE, 0x04CF, 0x04D0, 0x04D1, 0x04D2, 0x04D3, 0x04D4, 0x04D5, 0x04D6, 0x04D7, 0x04D8, 0x04D9, 0x04DA, 0x04DB, 0x04DC, 0x04DD, 0x04DE, 0x04DF, 0x04E0, 0x04E1, 0x04E2, 0x04E3, 0x04E4, 0x04E5, 0x04E6, 0x04E7, 0x04E8, 0x04E9, 0x04EA, 0x04EB, 0x04EC, 0x04ED, 0x04EE, 0x04EF, 0x04F0, 0x04F1};
u16 OoTMsgID[60] = {0};
u16 PicturesMsgID[60] = {0};
u16* storedQuestionSet;
u32 storedValue;
u16 checkKitanRequirement;



RECOMP_PATCH u16 EnKitan_GetQuestionMessageId(EnKitan* this) {
    s32 i = 0;
    f32 numQuestionsInSet;

    switch (recomp_get_config_u32("QuestionSet")) {
        case QUESTION_SET_VANILLA:
            default:
            storedQuestionSet = VanillaMsgID;
            numQuestionsInSet = 30.0f;
        break;
        case QUESTION_SET_CUSTOM:
            storedQuestionSet = CustomMsgID;
            numQuestionsInSet = 30.0f;
        break;
        case QUESTION_SET_OOT:
            storedQuestionSet = OoTMsgID;
            numQuestionsInSet = 30.0f;
        break;
        case QUESTION_SET_PICTURES:
            storedQuestionSet = PicturesMsgID;
            numQuestionsInSet = 30.0f;
        break;
    }   //Grabs the value of the setting in the config to determine what set of questions to call

    while (true) {
        s32 rand = Rand_ZeroFloat(numQuestionsInSet);
        storedValue = rand * 2;

        // Keep track of which questions have already been asked with a bitset
        if (!(this->textBitSet & (1 << rand))) {
            this->textBitSet |= 1 << rand;
            // 0x04B6 is the start of the question + answer choice textboxes, each question textbox is followed by the
            // choice textbox containing the answer choices
            return storedQuestionSet[storedValue];
        }

        i++;
        if (i > 1000) {
            // There's an assert(false) here in the debug version to catch any unforeseen issues in testing. It is
            // assumed that if this function is called there is always at least one question available to be selected.
        }
    }
}


void EnKitan_OfferPrize(EnKitan* this, PlayState* play);
void EnKitan_Leave(EnKitan* this, PlayState* play);
void EnKitan_SpawnEffects(EnKitan* this, PlayState* play, s32 numEffects);
void EnKitan_Appear(EnKitan* this, PlayState* play);
void EnKitan_Draw(Actor* thisx, PlayState* play);
void EnKitan_WaitToAppear(EnKitan* this, PlayState* play);
void EnKitan_Talk(EnKitan* this, PlayState* play);
s32 EnKitan_CanTalk(EnKitan* this, PlayState* play);
static ColliderCylinderInit sCylinderInit = {
    {
        COL_MATERIAL_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_ENEMY,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEM_MATERIAL_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xF7CFFFFF, 0x00, 0x00 },
        ATELEM_NONE | ATELEM_SFX_NORMAL,
        ACELEM_ON,
        OCELEM_ON,
    },
    { 20, 40, 0, { 0, 0, 0 } },
};

RECOMP_PATCH void EnKitan_WaitForPlayer(EnKitan* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);

    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        // Began talking
        this->actionFunc = EnKitan_Talk;
        Message_StartTextbox(play, 0x04B0, &this->actor);
        this->timer = 0;
        Animation_MorphToLoop(&this->skelAnime, &gKeatonChuckleAnim, -5.0f);
        switch (recomp_get_config_u32("QuestionSet")) {
        case QUESTION_SET_VANILLA:
            default:
            Audio_PlayFanfare(NA_BGM_KEATON_QUIZ);
        break;
        case QUESTION_SET_CUSTOM:
            Audio_PlayFanfare(NA_BGM_KEATON_QUIZ);
        break;
        case QUESTION_SET_OOT:
            Audio_PlayFanfare(NA_BGM_OWL);
        break;
        case QUESTION_SET_PICTURES:
            Audio_PlayFanfare(NA_BGM_KEATON_QUIZ);
        break;
    } // Uses the config setting for the question set and uses that to determine what song to use during the quiz
        
        return;
    }
    switch (recomp_get_config_u32("RequireKeatonMaskEquipped")) {
        case 0:
        default:
            checkKitanRequirement = (Player_GetMask(play) != PLAYER_MASK_KEATON);
            break;
        case 1:
            checkKitanRequirement = (INV_CONTENT(ITEM_MASK_KEATON) != ITEM_MASK_KEATON);
            break;
    }
    
    if ((this->timer <= 0) || checkKitanRequirement) {
    // If the player does not talk quickly enough or the player isn't wearing or owns the keaton mask, leave
    this->actionFunc = EnKitan_Leave;
    this->timer = 4;
    EnKitan_SpawnEffects(this, play, 30);
    SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 30, NA_SE_EN_NPC_FADEAWAY);
    return;
    }


    if (EnKitan_CanTalk(this, play)) {
        // Broadcast talk request for the player to accept
        Actor_OfferTalk(&this->actor, play, 130.0f);
        this->timer--;
    }
}

RECOMP_PATCH void EnKitan_Init(Actor* thisx, PlayState* play) {
    EnKitan* this = (EnKitan*)thisx;
    s32 pad;

    Actor_SetScale(&this->actor, 0.0f);
    this->actionFunc = EnKitan_WaitToAppear;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 12.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gKeatonSkel, &gKeatonIdleAnim, this->jointTable, this->morphTable,
                       KEATON_LIMB_MAX);
    Animation_PlayLoop(&this->skelAnime, &gKeatonIdleAnim);

    Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    Collider_UpdateCylinder(&this->actor, &this->collider);

    this->actor.velocity.y = -9.0f;
    this->actor.terminalVelocity = -9.0f;
    this->actor.gravity = -1.0f;
    switch (recomp_get_config_u32("RequireKeatonMaskEquipped")) {
        case 0:
        default:
            checkKitanRequirement = (Player_GetMask(play) != PLAYER_MASK_KEATON);
            break;
        case 1:
            checkKitanRequirement = (INV_CONTENT(ITEM_MASK_KEATON) != ITEM_MASK_KEATON);
            break;
    }
    if (checkKitanRequirement ||
        Flags_GetCollectible(play, ENKITAN_GET_COLLECT_FLAG(&this->actor))) {
        Actor_Kill(&this->actor);
        return;
    }

    this->timer = recomp_get_config_u32("KeatonAppearTimer") * 20;
    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
}

RECOMP_PATCH void EnKitan_Talk(EnKitan* this, PlayState* play) {
    if (SkelAnime_Update(&this->skelAnime)) {
        Animation_MorphToLoop(&this->skelAnime, &gKeatonIdleAnim, -10.0f);
        if (play->msgCtx.currentTextId != 0x04B4) {
            // If the quiz is ongoing, select a question
            Message_ContinueTextbox(play, EnKitan_GetQuestionMessageId(this));
        }
    }

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

            switch (play->msgCtx.currentTextId) {
                case 0x04B0:
                case 0x04B1:
                    // Intro text
                    Message_ContinueTextbox(play, play->msgCtx.currentTextId + 1);
                    break;

                case 0x04B2:
                    // Quiz begins
                    Animation_MorphToLoop(&this->skelAnime, &gKeatonIdleAnim, -5.0f);
                    Message_ContinueTextbox(play, EnKitan_GetQuestionMessageId(this));
                    break;

                case 0x04B4:
                    // Won the quiz
                    Message_CloseTextbox(play);
                    this->actionFunc = EnKitan_OfferPrize;
                    EnKitan_OfferPrize(this, play);
                    break;

                case 0x04B3:
                    // Answered a question incorrectly, stop
                    SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_FANFARE, 0);
                    if ((recomp_get_config_u32("CrashMoonOnFail") == 2)) {
                        play->nextEntrance = ENTRANCE(TERMINA_FIELD, 12);
                        gSaveContext.nextCutsceneIndex = 0;
                        play->transitionTrigger = TRANS_TRIGGER_START;
                        play->transitionType = TRANS_TYPE_FADE_WHITE;
                        //Causes a moon crash upon getting a question wrong
                    }
                    else if ((recomp_get_config_u32("CrashMoonOnFail") == 1)) {
                        kitanSendDeath();
                        //set health to 0 when getting a question wrong
                    }
                    else;
                    FALLTHROUGH;
                case 0x04B5:
                    // Keaton leaving
                    Message_CloseTextbox(play);
                    this->actionFunc = EnKitan_Leave;
                    this->timer = 4;
                    EnKitan_SpawnEffects(this, play, 30);
                    SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 30, NA_SE_EN_NPC_FADEAWAY);
                    Flags_SetCollectible(play, ENKITAN_GET_COLLECT_FLAG(&this->actor));
                    break;

                default:
                    if ((play->msgCtx.currentTextId == storedQuestionSet[storedValue])) {
                        // Checks the current message ID of the question
                        // Then adds 1 to the value for the corosponding answers
                        Message_ContinueTextbox(play, storedQuestionSet[storedValue + 1]);
                    }
                    break;
            }
            break;

        default:
            break;
    }
}
// make this include the a check if mask is worn or not
EZTR_MSG_CALLBACK(kitanInWrongLocation) {
    if (Player_GetMask(play) == PLAYER_MASK_KEATON){
        if (play->sceneId != SCENE_BACKTOWN && play->sceneId != SCENE_ROMANYMAE && play->sceneId != SCENE_10YUKIYAMANOMURA2) {
            buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
            EZTR_MsgSContent_Sprintf(buf->data.content, "Hee-hee-ho! Hello...?" EZTR_CC_NEWLINE "Where am I...?" EZTR_CC_NEWLINE "I'm not supposed to be here..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Anyway... Hee-hee-ho! Hello, child." EZTR_CC_NEWLINE "If you are attempting to fool me," EZTR_CC_NEWLINE "it is impossible." EZTR_CC_EVENT "" EZTR_CC_END "");
        } else  {
            // Vanilla Dialogue:
            EZTR_MsgSContent_Sprintf(buf->data.content, "Hee-hee-ho! Hello, child." EZTR_CC_NEWLINE "If you are attempting to fool me," EZTR_CC_NEWLINE "it is impossible." EZTR_CC_EVENT "" EZTR_CC_END "");
        }
    }
    else {
        if (play->sceneId != SCENE_BACKTOWN && play->sceneId != SCENE_ROMANYMAE && play->sceneId != SCENE_10YUKIYAMANOMURA2) {
            buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
            EZTR_MsgSContent_Sprintf(buf->data.content, "Hee-hee-ho! Hello...?" EZTR_CC_NEWLINE "Where am I...?" EZTR_CC_NEWLINE "I'm not supposed to be here..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Anyway... Hee-hee-ho! Hello, child." EZTR_CC_NEWLINE "I see you possess our mask," EZTR_CC_NEWLINE "it shall bring you good fortune." EZTR_CC_EVENT "" EZTR_CC_END "");
        } else  {
            
            EZTR_MsgSContent_Sprintf(buf->data.content, "Hee-hee-ho! Hello, child." EZTR_CC_NEWLINE "I see you possess our mask," EZTR_CC_NEWLINE "it shall bring you good fortune." EZTR_CC_EVENT "" EZTR_CC_END "");
        }
}
}
EZTR_MSG_CALLBACK(kitanCheckFormSheen) {
    Player* player = GET_PLAYER(play);
    if (Player_GetMask(play) == PLAYER_MASK_KEATON){
        buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                EZTR_MsgSContent_Sprintf(buf->data.content, "We Keatons can recognize our" EZTR_CC_NEWLINE "own by the sheen of our tails." EZTR_CC_EVENT "" EZTR_CC_END "");
    }   else if (player->transformation == PLAYER_FORM_HUMAN) {
                    buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                        EZTR_MsgSContent_Sprintf(buf->data.content, "You're from Hyrule, aren't you?" EZTR_CC_NEWLINE "Your arrival here so soon after" EZTR_CC_NEWLINE "the strange moon is alarming." EZTR_CC_EVENT "" EZTR_CC_END "");
    }   else if (player->transformation == PLAYER_FORM_DEKU) {
                    buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                        EZTR_MsgSContent_Sprintf(buf->data.content, "Do you know what happened at the" EZTR_CC_NEWLINE "Palace? I heard the Deku Princess" EZTR_CC_NEWLINE "was kidnapped! I do hope she's okay." EZTR_CC_EVENT "" EZTR_CC_END "");
    }   else if (player->transformation == PLAYER_FORM_GORON && play->sceneId != SCENE_10YUKIYAMANOMURA2) {
                    buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                        EZTR_MsgSContent_Sprintf(buf->data.content, "Are the Gorons staying warm?" EZTR_CC_NEWLINE "I heard there's an eternal Winter" EZTR_CC_NEWLINE "in the mountains. Hopefully Spring" EZTR_CC_NEWLINE "arrives soon." EZTR_CC_EVENT "" EZTR_CC_END "");
    }   else if (player->transformation == PLAYER_FORM_GORON && play->sceneId == SCENE_10YUKIYAMANOMURA2) {
                    buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                        EZTR_MsgSContent_Sprintf(buf->data.content, "I much prefer Spring. Wouldn't you" EZTR_CC_NEWLINE "agree? The Winters here are just" EZTR_CC_NEWLINE "too cold and it's difficult to keep" EZTR_CC_NEWLINE "my fur clean!" EZTR_CC_EVENT "" EZTR_CC_END "");
    }   else if (player->transformation == PLAYER_FORM_ZORA) {
                    buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                        EZTR_MsgSContent_Sprintf(buf->data.content, "What happened at Great Bay Coast?" EZTR_CC_NEWLINE "The sea is all murky and the stench" EZTR_CC_NEWLINE "is intense! Will you let me know" EZTR_CC_NEWLINE "when the water is clean?" EZTR_CC_EVENT "" EZTR_CC_END "");
    }   else if (player->transformation == PLAYER_FORM_FIERCE_DEITY) {
                    buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                        EZTR_MsgSContent_Sprintf(buf->data.content, "I sense a terrifying power coming" EZTR_CC_NEWLINE "from you. I truly hope you will use" EZTR_CC_NEWLINE "this power for the good of Termina" EZTR_CC_NEWLINE "and its people." EZTR_CC_EVENT "" EZTR_CC_END "");
    }   else if (player->transformation != PLAYER_FORM_HUMAN || player->transformation != PLAYER_FORM_DEKU || player->transformation != PLAYER_FORM_GORON || player->transformation != PLAYER_FORM_ZORA || player->transformation != PLAYER_FORM_FIERCE_DEITY) {
                    buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                        EZTR_MsgSContent_Sprintf(buf->data.content, "Your appearance is rather strange." EZTR_CC_NEWLINE "I almost didn't recognise you at all." EZTR_CC_EVENT "" EZTR_CC_END "");
    }
}
EZTR_MSG_CALLBACK(kitanCheckFormGood) {
    Player* player = GET_PLAYER(play);
    if (player->transformation == PLAYER_FORM_HUMAN){
        buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                EZTR_MsgSContent_Sprintf(buf->data.content, "But you're a good child..." EZTR_CC_NEWLINE "Let me put you to a test." EZTR_CC_EVENT "" EZTR_CC_END "");
    }   else{
        buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                EZTR_MsgSContent_Sprintf(buf->data.content, "I can tell this is not your true" EZTR_CC_NEWLINE "form... But you're a good child..." EZTR_CC_NEWLINE "Let me put you to a test." EZTR_CC_EVENT "" EZTR_CC_END "");
    }
}
EZTR_MSG_CALLBACK(kitanOnWrongAnswer) {
    if ((recomp_get_config_u32("CrashMoonOnFail") == 1)) { // set to Death, death specific text
        buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                EZTR_MsgSContent_Sprintf(buf->data.content, "Hee-hee-ho!" EZTR_CC_NEWLINE "Your training is insufficient!" EZTR_CC_NEWLINE "Please rest and come back more" EZTR_CC_NEWLINE "prepared, child." EZTR_CC_EVENT "" EZTR_CC_END "");
    }   else if ((recomp_get_config_u32("CrashMoonOnFail") == 2)) { // set to Moon Crash, moon specific text
        buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                EZTR_MsgSContent_Sprintf(buf->data.content, "Hee-hee-ho!" EZTR_CC_NEWLINE "Your training is insufficient!" EZTR_CC_NEWLINE "The moon will shed one last tear." EZTR_CC_EVENT "" EZTR_CC_END "");
    }   else if ((recomp_get_config_u32("CrashMoonOnFail") == 0)) { // set to Vanilla, default text
        buf->data.text_box_type = EZTR_STANDARD_TEXT_BOX_I,
                EZTR_MsgSContent_Sprintf(buf->data.content, "Hee-hee-ho!" EZTR_CC_NEWLINE "Your training is insufficient!" EZTR_CC_NEWLINE "Come back and try again, child!" EZTR_CC_EVENT "" EZTR_CC_END "");
    }
}

EZTR_ON_INIT void init_text() {
    // Replacements for Keaton Intro Text
    EZTR_Basic_ReplaceText(
        0x04B0,
        EZTR_STANDARD_TEXT_BOX_I,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "\xBF",
        kitanInWrongLocation
    );
        EZTR_Basic_ReplaceText(
    // Replacements for "We Keatons recognise our own by the sheen of our tail."
        0x04B1,
        EZTR_STANDARD_TEXT_BOX_I,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "\xBF",
        kitanCheckFormSheen
    );

    EZTR_Basic_ReplaceText(
        // Replacements for "But you're a good child... Let me put you to a test."
        0x04B2,
        EZTR_STANDARD_TEXT_BOX_I,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "\xBF",
        kitanCheckFormGood
    );
    EZTR_Basic_ReplaceText(
        // Replacements for getting a question wrong.
        0x04B3,
        EZTR_STANDARD_TEXT_BOX_I,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "\xBF",
        kitanOnWrongAnswer
    );
    //Vanilla Questions
        EZTR_Basic_ReplaceText(
        0x04B6,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "balloons" EZTR_CC_COLOR_DEFAULT " does " VARIABLE_TEXT_COLOR "Romani" EZTR_CC_COLOR_DEFAULT "," EZTR_CC_NEWLINE "the girl at the ranch, use during" EZTR_CC_NEWLINE "practice?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
        EZTR_Basic_ReplaceText(
        0x04EC,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "" VARIABLE_TEXT_COLOR "Mikau " EZTR_CC_COLOR_DEFAULT "is of which " VARIABLE_TEXT_COLOR "race" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04B8,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What " VARIABLE_TEXT_COLOR "weapon" EZTR_CC_COLOR_DEFAULT " does " VARIABLE_TEXT_COLOR "Romani" EZTR_CC_COLOR_DEFAULT ", the girl" EZTR_CC_NEWLINE "at the ranch, use in practice?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04BA,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What time does " VARIABLE_TEXT_COLOR "Romani" EZTR_CC_COLOR_DEFAULT ", the girl" EZTR_CC_NEWLINE "at the ranch, " VARIABLE_TEXT_COLOR "go to bed" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04BC,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE " " EZTR_CC_NEWLINE "" EZTR_CC_BOX_BREAK2 "At what time does " VARIABLE_TEXT_COLOR "Romani" EZTR_CC_COLOR_DEFAULT ", the" EZTR_CC_NEWLINE "ranch girl, " VARIABLE_TEXT_COLOR "wake up" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04BE,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " VARIABLE_TEXT_COLOR "name " EZTR_CC_COLOR_DEFAULT "given to you by" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Romani" EZTR_CC_COLOR_DEFAULT ", the girl at the ranch?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04C0,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "song" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "that " VARIABLE_TEXT_COLOR "Romani" EZTR_CC_COLOR_DEFAULT ", the girl at the ranch," EZTR_CC_NEWLINE "teaches you?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04C2,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many tiny " VARIABLE_TEXT_COLOR "cow figurines" EZTR_CC_COLOR_DEFAULT " are" EZTR_CC_NEWLINE "there in " VARIABLE_TEXT_COLOR "Clock Town" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04C4,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "cows" EZTR_CC_COLOR_DEFAULT " are there at" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Romani Ranch" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04C6,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "cuccos" EZTR_CC_COLOR_DEFAULT " are there in the" EZTR_CC_NEWLINE "barn at " VARIABLE_TEXT_COLOR "Romani Ranch" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04C8,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Where does " VARIABLE_TEXT_COLOR "Cremia" EZTR_CC_COLOR_DEFAULT ", manager of" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Romani Ranch" EZTR_CC_COLOR_DEFAULT ", try to deliver her" EZTR_CC_NEWLINE "milk?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04CA,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How old is " VARIABLE_TEXT_COLOR "Tingle" EZTR_CC_COLOR_DEFAULT ", the map" EZTR_CC_NEWLINE "salesman?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04CC,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What are the magic words that" EZTR_CC_NEWLINE "Tingle created?" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Tingle, Tingle...what" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04CE,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Is " VARIABLE_TEXT_COLOR "Tingle" EZTR_CC_COLOR_DEFAULT " the mapmaker " VARIABLE_TEXT_COLOR "left-handed" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "or " VARIABLE_TEXT_COLOR "right-handed" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04D0,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What color of" VARIABLE_TEXT_COLOR " trunks" EZTR_CC_COLOR_DEFAULT " does" VARIABLE_TEXT_COLOR " Tingle" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "the mapmaker wear?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04D2,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "festival" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "that is to be held in" VARIABLE_TEXT_COLOR " Clock Town" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04D4,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the" VARIABLE_TEXT_COLOR " mayor" EZTR_CC_COLOR_DEFAULT " of" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Clock Town" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04D6,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "vintage" EZTR_CC_NEWLINE "milk" EZTR_CC_COLOR_DEFAULT " sold at the " VARIABLE_TEXT_COLOR "Milk Bar" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04D8,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of Clock Town's" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "inn" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04DA,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What " VARIABLE_TEXT_COLOR "bad habit" EZTR_CC_COLOR_DEFAULT " does" VARIABLE_TEXT_COLOR " Anju" EZTR_CC_COLOR_DEFAULT ", the " EZTR_CC_NEWLINE "innkeeper, have?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04DC,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is " VARIABLE_TEXT_COLOR "Anju" EZTR_CC_COLOR_DEFAULT ", the innkeeper," EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "bad" EZTR_CC_COLOR_DEFAULT " at doing?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04DE,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of " VARIABLE_TEXT_COLOR "Anju's" EZTR_CC_NEWLINE "father" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04E0,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who is the " VARIABLE_TEXT_COLOR "leader" EZTR_CC_COLOR_DEFAULT " of the Bombers" EZTR_CC_NEWLINE "gang?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04E2,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Once it's completed, how " VARIABLE_TEXT_COLOR "tall " EZTR_CC_COLOR_DEFAULT "will" EZTR_CC_NEWLINE "the" VARIABLE_TEXT_COLOR " festival tower" EZTR_CC_COLOR_DEFAULT " at the" EZTR_CC_NEWLINE "carnival be?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04E4,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "mailboxes " EZTR_CC_COLOR_DEFAULT "are there in" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Clock Town" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04E6,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What does the owner of the " VARIABLE_TEXT_COLOR "Bomb" EZTR_CC_NEWLINE "Shop" EZTR_CC_COLOR_DEFAULT " call his " VARIABLE_TEXT_COLOR "mother" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04E8,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "singer" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "in the Zora band," EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "The Indigo-Go's" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04EA,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "members" EZTR_CC_COLOR_DEFAULT " are there in" EZTR_CC_NEWLINE "the Zora band, " VARIABLE_TEXT_COLOR "The Indigo-Go's" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04EE,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "" VARIABLE_TEXT_COLOR "Darmani" EZTR_CC_COLOR_DEFAULT " is of which " VARIABLE_TEXT_COLOR "race" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_ReplaceText(
        0x04F0,
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What " VARIABLE_TEXT_COLOR "instrument " EZTR_CC_COLOR_DEFAULT "does the " VARIABLE_TEXT_COLOR "Skull" EZTR_CC_NEWLINE "Kid " EZTR_CC_COLOR_DEFAULT "play?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    //Custom questions about MM
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion0),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "In Ikana, how many " VARIABLE_TEXT_COLOR "Gibdo" EZTR_CC_COLOR_DEFAULT " are " VARIABLE_TEXT_COLOR "" EZTR_CC_NEWLINE "Beneath the Well" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion1),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Throughout all of " VARIABLE_TEXT_COLOR "Termina" EZTR_CC_COLOR_DEFAULT "," EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "where can you find the " VARIABLE_TEXT_COLOR "Poe " EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "enemy?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion2),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Why won't the " VARIABLE_TEXT_COLOR "Postman" EZTR_CC_COLOR_DEFAULT " flee?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion3),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "Great Fairies" EZTR_CC_COLOR_DEFAULT " are in " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Termina"  EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion4),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What " VARIABLE_TEXT_COLOR "animal" EZTR_CC_COLOR_DEFAULT " is on the back of" EZTR_CC_NEWLINE "Anju's" VARIABLE_TEXT_COLOR " Grandmother's" EZTR_CC_COLOR_DEFAULT " wheelchair?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion5),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "We " VARIABLE_TEXT_COLOR "Keaton" EZTR_CC_COLOR_DEFAULT " will appear in" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "North Clock Town " EZTR_CC_COLOR_DEFAULT "and " VARIABLE_TEXT_COLOR "Milk Road" EZTR_CC_COLOR_DEFAULT"." EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Where else" EZTR_CC_COLOR_DEFAULT" can we appear?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion6),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What " VARIABLE_TEXT_COLOR "instrument" EZTR_CC_COLOR_DEFAULT " does " VARIABLE_TEXT_COLOR "Evan " EZTR_CC_COLOR_DEFAULT "of the" EZTR_CC_NEWLINE "Zora band, " VARIABLE_TEXT_COLOR "The Indigo-Go's" EZTR_CC_COLOR_DEFAULT" play?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion7),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of the " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "King of Ikana" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion8),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " VARIABLE_TEXT_COLOR "weapon" EZTR_CC_COLOR_DEFAULT " of choice for " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Gomess" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion9),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " VARIABLE_TEXT_COLOR "weapon" EZTR_CC_COLOR_DEFAULT " of choice for " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Odolwa" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion10),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who has the " VARIABLE_TEXT_COLOR "title" EZTR_CC_COLOR_DEFAULT " of " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Masked Mechanical Monster" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion11),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who has the " VARIABLE_TEXT_COLOR "title" EZTR_CC_COLOR_DEFAULT " of " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Gargantuan Masked Fish" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion12),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who has the " VARIABLE_TEXT_COLOR "title" EZTR_CC_COLOR_DEFAULT " of " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Giant Masked Insect" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion13),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "song" EZTR_CC_NEWLINE "Toto" EZTR_CC_COLOR_DEFAULT " of the Zora asks you to " EZTR_CC_NEWLINE "play in the " VARIABLE_TEXT_COLOR "Milk Bar" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
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
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion14),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What can " VARIABLE_TEXT_COLOR "Cremia" EZTR_CC_COLOR_DEFAULT ", manager of" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Romani Ranch" EZTR_CC_COLOR_DEFAULT ", randomly give you " EZTR_CC_NEWLINE "if you already have the" VARIABLE_TEXT_COLOR " Romani" EZTR_CC_NEWLINE "Mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer14),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "A firm handshake" EZTR_CC_NEWLINE "A sweet kiss" EZTR_CC_NEWLINE "A warm hug" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion15),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "strikes" EZTR_CC_COLOR_DEFAULT " can the " VARIABLE_TEXT_COLOR "Razor" EZTR_CC_NEWLINE "Sword " EZTR_CC_COLOR_DEFAULT "endure before its edges" EZTR_CC_NEWLINE "become dull and it revert back" EZTR_CC_NEWLINE "to the " VARIABLE_TEXT_COLOR "Kokiri Sword" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer15),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "100" EZTR_CC_NEWLINE "200" EZTR_CC_NEWLINE "Its edges never dull" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion16),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "Rupees" EZTR_CC_COLOR_DEFAULT " does the " VARIABLE_TEXT_COLOR "Postman" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "charge to retry his " VARIABLE_TEXT_COLOR "Mental Training" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "challenge?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer16),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "2 Rupees" EZTR_CC_NEWLINE "5 Rupees" EZTR_CC_NEWLINE "He doesn't charge anything" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion17),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "Octorok" EZTR_CC_COLOR_DEFAULT " are required to" EZTR_CC_NEWLINE "be defeated in the " VARIABLE_TEXT_COLOR "Town Shooting" EZTR_CC_NEWLINE "Gallery " EZTR_CC_COLOR_DEFAULT "for a " VARIABLE_TEXT_COLOR "perfect" EZTR_CC_COLOR_DEFAULT " score?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer17),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "40" EZTR_CC_NEWLINE "50" EZTR_CC_NEWLINE "60" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion18),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who is " VARIABLE_TEXT_COLOR "Tingle" EZTR_CC_COLOR_DEFAULT "'s father?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer18),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Mayor Dotour" EZTR_CC_NEWLINE "Swamp Shooting Gallery Guy" EZTR_CC_NEWLINE "Swamp Tourist Center Guide" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion19),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "little girl" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "who lives with her father in " VARIABLE_TEXT_COLOR "Ikana" EZTR_CC_COLOR_DEFAULT "'s " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Music Box House" EZTR_CC_COLOR_DEFAULT"?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer19),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Meg" EZTR_CC_NEWLINE "Joelle" EZTR_CC_NEWLINE "Pamela" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion20),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "red" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "Poe Sister?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer20),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Joelle" EZTR_CC_NEWLINE "Beth" EZTR_CC_NEWLINE "Amy" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion21),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "blue" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "Poe Sister?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer21),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Joelle" EZTR_CC_NEWLINE "Beth" EZTR_CC_NEWLINE "Amy" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion22),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "green" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "Poe Sister?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer22),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Beth" EZTR_CC_NEWLINE "Amy" EZTR_CC_NEWLINE "Meg" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion23),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "purple" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "Poe Sister?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer23),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Beth" EZTR_CC_NEWLINE "Amy" EZTR_CC_NEWLINE "Meg" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion24),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "song" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "that the " VARIABLE_TEXT_COLOR "King of Ikana" EZTR_CC_COLOR_DEFAULT " teaches you?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer24),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Elegy of Emptiness" EZTR_CC_NEWLINE "Song of Storms" EZTR_CC_NEWLINE "Requiem of Spirit" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion25),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "Stalchildren " EZTR_CC_COLOR_DEFAULT "are inside "EZTR_CC_NEWLINE "the " VARIABLE_TEXT_COLOR "Oceanside Spider House" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer25),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Six" EZTR_CC_NEWLINE "Seven" EZTR_CC_NEWLINE "There are none" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion26),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "Rupees " EZTR_CC_COLOR_DEFAULT "will the "EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Curiosity Shop Owner " EZTR_CC_COLOR_DEFAULT "offer in " EZTR_CC_NEWLINE "exchange for the " VARIABLE_TEXT_COLOR "Deku Princess" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer26),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "50" EZTR_CC_NEWLINE "200" EZTR_CC_NEWLINE "He refuses to buy" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion27),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "hearts " EZTR_CC_COLOR_DEFAULT "must you have "EZTR_CC_NEWLINE "to challenge " VARIABLE_TEXT_COLOR "Wart " EZTR_CC_COLOR_DEFAULT "in Ikana's " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Secret Shrine" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer27),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Eight" EZTR_CC_NEWLINE "Twelve" EZTR_CC_NEWLINE "Sixteen" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion28),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " VARIABLE_TEXT_COLOR "law " EZTR_CC_COLOR_DEFAULT "of the " VARIABLE_TEXT_COLOR "Garo" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Die I shall," EZTR_CC_COLOR_DEFAULT " ...what?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer28),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Leaving no corpse" EZTR_CC_NEWLINE "Without any remorse" EZTR_CC_NEWLINE "But never forgotten" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomQuestion29),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "leader" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "of the " VARIABLE_TEXT_COLOR "Gerudo Pirates" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(CustomAnswer29),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Nabooru" EZTR_CC_NEWLINE "Linebeck" EZTR_CC_NEWLINE "Aveil" EZTR_CC_END "",
        quiz_color_changer
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
    CustomMsgID[28] = EZTR_GET_ID_H(CustomQuestion14);
    CustomMsgID[29] = EZTR_GET_ID_H(CustomAnswer14);
    CustomMsgID[30] = EZTR_GET_ID_H(CustomQuestion15);
    CustomMsgID[31] = EZTR_GET_ID_H(CustomAnswer15);
    CustomMsgID[32] = EZTR_GET_ID_H(CustomQuestion16);
    CustomMsgID[33] = EZTR_GET_ID_H(CustomAnswer16);
    CustomMsgID[34] = EZTR_GET_ID_H(CustomQuestion17);
    CustomMsgID[35] = EZTR_GET_ID_H(CustomAnswer17);
    CustomMsgID[36] = EZTR_GET_ID_H(CustomQuestion18);
    CustomMsgID[37] = EZTR_GET_ID_H(CustomAnswer18);
    CustomMsgID[38] = EZTR_GET_ID_H(CustomQuestion19);
    CustomMsgID[39] = EZTR_GET_ID_H(CustomAnswer19);
    CustomMsgID[40] = EZTR_GET_ID_H(CustomQuestion20);
    CustomMsgID[41] = EZTR_GET_ID_H(CustomAnswer20);
    CustomMsgID[42] = EZTR_GET_ID_H(CustomQuestion21);
    CustomMsgID[43] = EZTR_GET_ID_H(CustomAnswer21);
    CustomMsgID[44] = EZTR_GET_ID_H(CustomQuestion22);
    CustomMsgID[45] = EZTR_GET_ID_H(CustomAnswer22);
    CustomMsgID[46] = EZTR_GET_ID_H(CustomQuestion23);
    CustomMsgID[47] = EZTR_GET_ID_H(CustomAnswer23);
    CustomMsgID[48] = EZTR_GET_ID_H(CustomQuestion24);
    CustomMsgID[49] = EZTR_GET_ID_H(CustomAnswer24);
    CustomMsgID[50] = EZTR_GET_ID_H(CustomQuestion25);
    CustomMsgID[51] = EZTR_GET_ID_H(CustomAnswer25);
    CustomMsgID[52] = EZTR_GET_ID_H(CustomQuestion26);
    CustomMsgID[53] = EZTR_GET_ID_H(CustomAnswer26);
    CustomMsgID[54] = EZTR_GET_ID_H(CustomQuestion27);
    CustomMsgID[55] = EZTR_GET_ID_H(CustomAnswer27);
    CustomMsgID[56] = EZTR_GET_ID_H(CustomQuestion28);
    CustomMsgID[57] = EZTR_GET_ID_H(CustomAnswer28);
    CustomMsgID[58] = EZTR_GET_ID_H(CustomQuestion29);
    CustomMsgID[59] = EZTR_GET_ID_H(CustomAnswer29);

    //OoT questions
	EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion0),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "cucco" EZTR_CC_COLOR_DEFAULT " are in" VARIABLE_TEXT_COLOR "" EZTR_CC_NEWLINE "Kakariko Village" EZTR_CC_COLOR_DEFAULT " as a child?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer0),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Six" EZTR_CC_NEWLINE "Seven" EZTR_CC_NEWLINE "Eight" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion1),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Throughout all of " VARIABLE_TEXT_COLOR "Hyrule" EZTR_CC_COLOR_DEFAULT "," EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "how many " VARIABLE_TEXT_COLOR "Gold Skulltulas " EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "are there in total?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer1),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "50" EZTR_CC_NEWLINE "100" EZTR_CC_NEWLINE "120" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion2),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is " VARIABLE_TEXT_COLOR "Damp\x9D" EZTR_CC_COLOR_DEFAULT ", Kakariko Village's"  EZTR_CC_NEWLINE "Gravekeeper afraid of?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer2),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Ghosts" EZTR_CC_NEWLINE "The dark" EZTR_CC_NEWLINE "Rabbits" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion3),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "Great Fairies" EZTR_CC_COLOR_DEFAULT " are in " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Hyrule"  EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer3),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Four" EZTR_CC_NEWLINE "Five" EZTR_CC_NEWLINE "Six" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion4),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What " VARIABLE_TEXT_COLOR "song" EZTR_CC_COLOR_DEFAULT " is taught to you by" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Shiek" EZTR_CC_COLOR_DEFAULT " inside " VARIABLE_TEXT_COLOR "Death Mountain Crater" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer4),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Nocturne of Fire" EZTR_CC_NEWLINE "Bolero of Fire" EZTR_CC_NEWLINE "Minuet of Fire" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion5),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "We " VARIABLE_TEXT_COLOR "Keaton" EZTR_CC_COLOR_DEFAULT " are popular with" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "children " EZTR_CC_COLOR_DEFAULT "in " VARIABLE_TEXT_COLOR "Hyrule" EZTR_CC_COLOR_DEFAULT"." EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "will buy our Mask from you?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer5),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Kakariko Village Gate Guard" EZTR_CC_NEWLINE "Castle Town Gate Guard" EZTR_CC_NEWLINE "Hyrule Castle Gate Guard" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion6),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What " VARIABLE_TEXT_COLOR "instrument" EZTR_CC_COLOR_DEFAULT " does " VARIABLE_TEXT_COLOR "Shiek " EZTR_CC_COLOR_DEFAULT "of the" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Shiekah" EZTR_CC_COLOR_DEFAULT" play?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer6),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Grass whistle" EZTR_CC_NEWLINE "Ocarina" EZTR_CC_NEWLINE "Harp" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion7),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of the " EZTR_CC_NEWLINE "leader of the" VARIABLE_TEXT_COLOR " Kokiri" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer7),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Fado" EZTR_CC_NEWLINE "Mido" EZTR_CC_NEWLINE "Bedo" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion8),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " VARIABLE_TEXT_COLOR "weapon" EZTR_CC_COLOR_DEFAULT " of choice for " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Iron Knuckles" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer8),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Scythe" EZTR_CC_NEWLINE "Sword and shield" EZTR_CC_NEWLINE "Battle-axe" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion9),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " VARIABLE_TEXT_COLOR "weapon" EZTR_CC_COLOR_DEFAULT " of choice for " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Stalfos" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer9),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Scythe" EZTR_CC_NEWLINE "Sword and shield" EZTR_CC_NEWLINE "Battle-axe" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion10),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who is the " VARIABLE_TEXT_COLOR "Sage" EZTR_CC_COLOR_DEFAULT " of " VARIABLE_TEXT_COLOR "Fire" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer10),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Saria" EZTR_CC_NEWLINE "Darmani" EZTR_CC_NEWLINE "Darunia" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion11),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who is the " VARIABLE_TEXT_COLOR "sage" EZTR_CC_COLOR_DEFAULT " of " VARIABLE_TEXT_COLOR "Water" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer11),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Mipha" EZTR_CC_NEWLINE "Ruto" EZTR_CC_NEWLINE "Lulu" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion12),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who is the " VARIABLE_TEXT_COLOR "sage" EZTR_CC_COLOR_DEFAULT " of " VARIABLE_TEXT_COLOR "Shadow" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer12),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Impaz" EZTR_CC_NEWLINE "Sheik" EZTR_CC_NEWLINE "Impa" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion13),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the name of the " VARIABLE_TEXT_COLOR "song" EZTR_CC_NEWLINE "Sheik" EZTR_CC_COLOR_DEFAULT " of the Sheikah teaches " EZTR_CC_NEWLINE "you in " VARIABLE_TEXT_COLOR "Kakariko Village" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer13),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Nocturne of the Dead" EZTR_CC_NEWLINE "Nocturne of Shadow" EZTR_CC_NEWLINE "Nocturne of Sorrow" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion14),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What happens when you play " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Song of Storms" EZTR_CC_COLOR_DEFAULT " in front of a" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Gossip Stone" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer14),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "It spins around" EZTR_CC_NEWLINE "It speaks to you" EZTR_CC_NEWLINE "It spawns a Big Fairy" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion15),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What can you find in the " VARIABLE_TEXT_COLOR "" EZTR_CC_NEWLINE "center " EZTR_CC_COLOR_DEFAULT "of the maze inside the " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Gerudo Training Grounds" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer15),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Ice Arrow" EZTR_CC_NEWLINE "Iron Boots" EZTR_CC_NEWLINE "Gerudo Membership Card" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion16),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Where does the " VARIABLE_TEXT_COLOR "Cucco Lady" EZTR_CC_COLOR_DEFAULT " go" EZTR_CC_NEWLINE "to study how to breed " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "pocket-sized Cuccos" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer16),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Lakeside Laboratory" EZTR_CC_NEWLINE "Hyrule Market" EZTR_CC_NEWLINE "Lon Lon Ranch" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion17),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Contrary to her elegant image," EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Princess Zelda" EZTR_CC_COLOR_DEFAULT " is in fact, what?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer17),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "A strict ruler" EZTR_CC_NEWLINE "A tomboy" EZTR_CC_NEWLINE "Hot-headed" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion18),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Who is " VARIABLE_TEXT_COLOR "Malon" EZTR_CC_COLOR_DEFAULT "'s father?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer18),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Ingo" EZTR_CC_NEWLINE "Muto" EZTR_CC_NEWLINE "Talon" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion19),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What does the " VARIABLE_TEXT_COLOR "Kokiri " EZTR_CC_COLOR_DEFAULT "with blonde" EZTR_CC_NEWLINE "hair in the " VARIABLE_TEXT_COLOR "Lost Woods" EZTR_CC_COLOR_DEFAULT " give you in" EZTR_CC_NEWLINE "exchange for the " VARIABLE_TEXT_COLOR "Odd Potion" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer19),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Broken Goron Sword" EZTR_CC_NEWLINE "Blue Potion" EZTR_CC_NEWLINE "Poacher's Saw" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion20),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What happens when you play the " EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Song of Time" EZTR_CC_COLOR_DEFAULT "next to a " VARIABLE_TEXT_COLOR "Song of" EZTR_CC_NEWLINE "Time block" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer20),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "It travels through time" EZTR_CC_NEWLINE "It explodes" EZTR_CC_NEWLINE "It heals you" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion21),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What " VARIABLE_TEXT_COLOR "Magic Spell" EZTR_CC_COLOR_DEFAULT " does the" VARIABLE_TEXT_COLOR " Great" EZTR_CC_NEWLINE "Fairy" EZTR_CC_COLOR_DEFAULT " in " VARIABLE_TEXT_COLOR "Zora's Fountain " EZTR_CC_COLOR_DEFAULT "grant you?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer21),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Din's Fire" EZTR_CC_NEWLINE "Farore's Wind" EZTR_CC_NEWLINE "Nayru's Love" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion22),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What happens when you play the" EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "Sun's Song" EZTR_CC_COLOR_DEFAULT "near a Redead?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer22),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "The Redead becomes a Big Fairy" EZTR_CC_NEWLINE "The Redead is stunned" EZTR_CC_NEWLINE "The Redead dies" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion23),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How many " VARIABLE_TEXT_COLOR "unique Gossip Stones" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "are scattered across Hyrule?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer23),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "48" EZTR_CC_NEWLINE "40" EZTR_CC_NEWLINE "32" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion24),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What do the " VARIABLE_TEXT_COLOR "Gerudo women" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "look for when they visit " VARIABLE_TEXT_COLOR "Hyrule" EZTR_CC_NEWLINE "Castle Town" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer24),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Boyfriends" EZTR_CC_NEWLINE "Weapons and armor" EZTR_CC_NEWLINE "Horses" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion25),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Defeating multiple " VARIABLE_TEXT_COLOR "Stalchildren " EZTR_CC_COLOR_DEFAULT "and " VARIABLE_TEXT_COLOR "" EZTR_CC_NEWLINE "Guays" EZTR_CC_COLOR_DEFAULT " causes big variants to appear." EZTR_CC_NEWLINE "What other enemy can do this?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer25),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Leever" EZTR_CC_NEWLINE "Keese" EZTR_CC_NEWLINE "There are none" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion26),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What item of " VARIABLE_TEXT_COLOR "clothing " EZTR_CC_COLOR_DEFAULT "is against the "EZTR_CC_NEWLINE "" VARIABLE_TEXT_COLOR "rules " EZTR_CC_COLOR_DEFAULT "in the " VARIABLE_TEXT_COLOR "Treasure Chest Shop" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer26),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Heavy boots" EZTR_CC_NEWLINE "Gauntlets" EZTR_CC_NEWLINE "Glasses" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion27),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the small " VARIABLE_TEXT_COLOR "animal " EZTR_CC_COLOR_DEFAULT "that "EZTR_CC_NEWLINE "the " VARIABLE_TEXT_COLOR "Potion Lady " EZTR_CC_COLOR_DEFAULT "keeps on her desk?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer27),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Dog" EZTR_CC_NEWLINE "Tiger" EZTR_CC_NEWLINE "Cucco" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion28),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "How did" VARIABLE_TEXT_COLOR " Damp\x9D" EZTR_CC_COLOR_DEFAULT ", Kakariko Village's"  EZTR_CC_NEWLINE "Gravekeeper, obtain the" VARIABLE_TEXT_COLOR " Hookshot" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer28),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Digging a hole" EZTR_CC_NEWLINE "Inside a grave" EZTR_CC_NEWLINE "Gift from a friend" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTQuestion29),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Answer me this..." EZTR_CC_NEWLINE "About your adventures in Hyrule..." EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "What is the " VARIABLE_TEXT_COLOR "Zora's Sapphire" EZTR_CC_COLOR_DEFAULT " used " EZTR_CC_NEWLINE "for by Zora royalty?" EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(OoTAnswer29),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Water powers" EZTR_CC_NEWLINE "Proof of royalty" EZTR_CC_NEWLINE "Engagement ring" EZTR_CC_END "",
        quiz_color_changer
    );
    OoTMsgID[0] = EZTR_GET_ID_H(OoTQuestion0);
    OoTMsgID[1] = EZTR_GET_ID_H(OoTAnswer0);
    OoTMsgID[2] = EZTR_GET_ID_H(OoTQuestion1);
    OoTMsgID[3] = EZTR_GET_ID_H(OoTAnswer1);
    OoTMsgID[4] = EZTR_GET_ID_H(OoTQuestion2);
    OoTMsgID[5] = EZTR_GET_ID_H(OoTAnswer2);
    OoTMsgID[6] = EZTR_GET_ID_H(OoTQuestion3);
    OoTMsgID[7] = EZTR_GET_ID_H(OoTAnswer3);
    OoTMsgID[8] = EZTR_GET_ID_H(OoTQuestion4);
    OoTMsgID[9] = EZTR_GET_ID_H(OoTAnswer4);
    OoTMsgID[10] = EZTR_GET_ID_H(OoTQuestion5);
    OoTMsgID[11] = EZTR_GET_ID_H(OoTAnswer5);
    OoTMsgID[12] = EZTR_GET_ID_H(OoTQuestion6);
    OoTMsgID[13] = EZTR_GET_ID_H(OoTAnswer6);
    OoTMsgID[14] = EZTR_GET_ID_H(OoTQuestion7);
    OoTMsgID[15] = EZTR_GET_ID_H(OoTAnswer7);
    OoTMsgID[16] = EZTR_GET_ID_H(OoTQuestion8);
    OoTMsgID[17] = EZTR_GET_ID_H(OoTAnswer8);
    OoTMsgID[18] = EZTR_GET_ID_H(OoTQuestion9);
    OoTMsgID[19] = EZTR_GET_ID_H(OoTAnswer9);
    OoTMsgID[20] = EZTR_GET_ID_H(OoTQuestion10);
    OoTMsgID[21] = EZTR_GET_ID_H(OoTAnswer10);
    OoTMsgID[22] = EZTR_GET_ID_H(OoTQuestion11);
    OoTMsgID[23] = EZTR_GET_ID_H(OoTAnswer11);
    OoTMsgID[24] = EZTR_GET_ID_H(OoTQuestion12);
    OoTMsgID[25] = EZTR_GET_ID_H(OoTAnswer12);
    OoTMsgID[26] = EZTR_GET_ID_H(OoTQuestion13);
    OoTMsgID[27] = EZTR_GET_ID_H(OoTAnswer13);
    OoTMsgID[28] = EZTR_GET_ID_H(OoTQuestion14);
    OoTMsgID[29] = EZTR_GET_ID_H(OoTAnswer14);
    OoTMsgID[30] = EZTR_GET_ID_H(OoTQuestion15);
    OoTMsgID[31] = EZTR_GET_ID_H(OoTAnswer15);
    OoTMsgID[32] = EZTR_GET_ID_H(OoTQuestion16);
    OoTMsgID[33] = EZTR_GET_ID_H(OoTAnswer16);
    OoTMsgID[34] = EZTR_GET_ID_H(OoTQuestion17);
    OoTMsgID[35] = EZTR_GET_ID_H(OoTAnswer17);
    OoTMsgID[36] = EZTR_GET_ID_H(OoTQuestion18);
    OoTMsgID[37] = EZTR_GET_ID_H(OoTAnswer18);
    OoTMsgID[38] = EZTR_GET_ID_H(OoTQuestion19);
    OoTMsgID[39] = EZTR_GET_ID_H(OoTAnswer19);
    OoTMsgID[40] = EZTR_GET_ID_H(OoTQuestion20);
    OoTMsgID[41] = EZTR_GET_ID_H(OoTAnswer20);
    OoTMsgID[42] = EZTR_GET_ID_H(OoTQuestion21);
    OoTMsgID[43] = EZTR_GET_ID_H(OoTAnswer21);
    OoTMsgID[44] = EZTR_GET_ID_H(OoTQuestion22);
    OoTMsgID[45] = EZTR_GET_ID_H(OoTAnswer22);
    OoTMsgID[46] = EZTR_GET_ID_H(OoTQuestion23);
    OoTMsgID[47] = EZTR_GET_ID_H(OoTAnswer23);
    OoTMsgID[48] = EZTR_GET_ID_H(OoTQuestion24);
    OoTMsgID[49] = EZTR_GET_ID_H(OoTAnswer24);
    OoTMsgID[50] = EZTR_GET_ID_H(OoTQuestion25);
    OoTMsgID[51] = EZTR_GET_ID_H(OoTAnswer25);
    OoTMsgID[52] = EZTR_GET_ID_H(OoTQuestion26);
    OoTMsgID[53] = EZTR_GET_ID_H(OoTAnswer26);
    OoTMsgID[54] = EZTR_GET_ID_H(OoTQuestion27);
    OoTMsgID[55] = EZTR_GET_ID_H(OoTAnswer27);
    OoTMsgID[56] = EZTR_GET_ID_H(OoTQuestion28);
    OoTMsgID[57] = EZTR_GET_ID_H(OoTAnswer28);
    OoTMsgID[58] = EZTR_GET_ID_H(OoTQuestion29);
    OoTMsgID[59] = EZTR_GET_ID_H(OoTAnswer29);
    // Pictures Questions
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion0),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_ANJU,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "is this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer0),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Zelda" EZTR_CC_NEWLINE "Anju" EZTR_CC_NEWLINE "Aryll" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion1),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_KAFEI,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "is this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer1),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Link" EZTR_CC_NEWLINE "Kafei" EZTR_CC_NEWLINE "Mayor Dotour" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion2),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_ROMANI,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "is this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer2),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Cremia" EZTR_CC_NEWLINE "Malon" EZTR_CC_NEWLINE "Romani" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion3),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_KAMARO,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "is this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer3),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Kirito" EZTR_CC_NEWLINE "Kotaro" EZTR_CC_NEWLINE "Kamaro" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion4),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_GROG,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "is this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer4),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Greg" EZTR_CC_NEWLINE "Grog" EZTR_CC_NEWLINE "Grok" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion5),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_CREMIA,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "is this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer5),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Cremia" EZTR_CC_NEWLINE "Malon" EZTR_CC_NEWLINE "Romani" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion6),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_TOTO,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "is this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer6),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Lulu" EZTR_CC_NEWLINE "Mikau" EZTR_CC_NEWLINE "Toto" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion7),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_SHIRO,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "is this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer7),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Mutoh" EZTR_CC_NEWLINE "Shiro" EZTR_CC_NEWLINE "Kamaro" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion8),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_MADAME_AROMA,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "is this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );

    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer8),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Madame Angela" EZTR_CC_NEWLINE "Madame Amelia" EZTR_CC_NEWLINE "Madame Aroma" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion9),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_TOILET_HAND,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        VARIABLE_TEXT_COLOR "Who " EZTR_CC_COLOR_DEFAULT "is this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer9),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Andy" EZTR_CC_NEWLINE "???" EZTR_CC_NEWLINE "!!!" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion10),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_HEROS_BOW,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer10),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Bow and Arrow" EZTR_CC_NEWLINE "Fairy Bow" EZTR_CC_NEWLINE "Hero's Bow" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion11),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_PICTOGRAPH_BOX_1,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer11),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Photograph Box" EZTR_CC_NEWLINE "Pictograph Box" EZTR_CC_NEWLINE "Picto Box" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion12),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_MIRROR_SHIELD,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer12),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Reflector Shield" EZTR_CC_NEWLINE "Shiny Shield" EZTR_CC_NEWLINE "Mirror Shield" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion13),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_ROOM_KEY,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer13),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Inn Key" EZTR_CC_NEWLINE "Room Key" EZTR_CC_NEWLINE "House Key" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion14),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_GILDED_SWORD,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer14),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Perfect Sword" EZTR_CC_NEWLINE "Golden Sword" EZTR_CC_NEWLINE "Gilded Sword" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion15),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_KOKIRI_SWORD,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer15),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Kokiri Sword" EZTR_CC_NEWLINE "Hero's Sword" EZTR_CC_NEWLINE "Practice Sword" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion16),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_HEROS_SHIELD,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer16),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Hero's Shield" EZTR_CC_NEWLINE "Hylian Shield" EZTR_CC_NEWLINE "Link's Shield" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion17),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_PENDANT_OF_MEMORIES,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer17),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Joy Pendant" EZTR_CC_NEWLINE "Pendant of Memories" EZTR_CC_NEWLINE "Beetle Necklace" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion18),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_LETTER_TO_KAFEI,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer18),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Letter to Mama" EZTR_CC_NEWLINE "Letter to Anju" EZTR_CC_NEWLINE "Letter to Kafei" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion19),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_CHATEAU_ROMANI,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "What is the " VARIABLE_TEXT_COLOR "name" EZTR_CC_COLOR_DEFAULT " of this?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer19),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Lon Lon Milk" EZTR_CC_NEWLINE "Bottle of Milk" EZTR_CC_NEWLINE "Chateau Romani" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion20),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_ROMANI_MASK,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Who gave you this " VARIABLE_TEXT_COLOR "mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer20),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Cremia" EZTR_CC_NEWLINE "Romani" EZTR_CC_NEWLINE "Barten" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion21),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_COUPLES_MASK,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Who gave you this " VARIABLE_TEXT_COLOR "mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer21),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Cremia and Romani" EZTR_CC_NEWLINE "Anju and Kafei" EZTR_CC_NEWLINE "Mayor Dotour and Madame Aroma" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion22),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_STONE_MASK,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Who gave you this " VARIABLE_TEXT_COLOR "mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer22),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Shingo" EZTR_CC_NEWLINE "Shiro" EZTR_CC_NEWLINE "Shien" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion23),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_CAPTAINS_HAT,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Who gave you this " VARIABLE_TEXT_COLOR "mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer23),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Igos du Ikana" EZTR_CC_NEWLINE "Captain Keaton" EZTR_CC_NEWLINE "Captain Keeta" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion24),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_FIERCE_DEITY_MASK,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Who gave you this " VARIABLE_TEXT_COLOR "mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer24),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Moon Child wearing Majora's Mask" EZTR_CC_NEWLINE "Moon Child wearing Goht's Remains" EZTR_CC_NEWLINE "Happy Mask Salesman" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion25),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_BUNNY_HOOD,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Who gave you this " VARIABLE_TEXT_COLOR "mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer25),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Grog" EZTR_CC_NEWLINE "The Postman" EZTR_CC_NEWLINE "Anju" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion26),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_KEATON_MASK,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Who gave you this " VARIABLE_TEXT_COLOR "mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer26),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Kafei" EZTR_CC_NEWLINE "Keaton" EZTR_CC_NEWLINE "Man from Curiosity Shop" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion27),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_BLAST_MASK,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Who gave you this " VARIABLE_TEXT_COLOR "mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer27),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0002,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Man from Curiosity Shop" EZTR_CC_NEWLINE "Old Lady from Bomb Shop" EZTR_CC_NEWLINE "Goron inside Bomb Shop" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion28),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_MASK_OF_SCENTS,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Who gave you this " VARIABLE_TEXT_COLOR "mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer28),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0001,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Deku Butler" EZTR_CC_NEWLINE "Deku King" EZTR_CC_NEWLINE "Deku Princess" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesQuestion29),
        EZTR_STANDARD_TEXT_BOX_II,
        0,
        EZTR_ICON_DON_GEROS_MASK,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        false,
        "Who gave you this " VARIABLE_TEXT_COLOR "mask" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "Pick one of the three choices..." EZTR_CC_EVENT "" EZTR_CC_END "",
        quiz_color_changer
    );
    EZTR_Basic_AddCustomText(EZTR_HNAME(PicturesAnswer29),
        EZTR_STANDARD_TEXT_BOX_II,
        1,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        0x0003,
        EZTR_NO_VALUE,
        false,
        "" EZTR_CC_THREE_CHOICE "" EZTR_CC_COLOR_GREEN "Gekko" EZTR_CC_NEWLINE "Don Gero" EZTR_CC_NEWLINE "Hungry Goron" EZTR_CC_END "",
        quiz_color_changer
    );
    PicturesMsgID[0] = EZTR_GET_ID_H(PicturesQuestion0);
    PicturesMsgID[1] = EZTR_GET_ID_H(PicturesAnswer0);
    PicturesMsgID[2] = EZTR_GET_ID_H(PicturesQuestion1);
    PicturesMsgID[3] = EZTR_GET_ID_H(PicturesAnswer1);
    PicturesMsgID[4] = EZTR_GET_ID_H(PicturesQuestion2);
    PicturesMsgID[5] = EZTR_GET_ID_H(PicturesAnswer2);
    PicturesMsgID[6] = EZTR_GET_ID_H(PicturesQuestion3);
    PicturesMsgID[7] = EZTR_GET_ID_H(PicturesAnswer3);
    PicturesMsgID[8] = EZTR_GET_ID_H(PicturesQuestion4);
    PicturesMsgID[9] = EZTR_GET_ID_H(PicturesAnswer4);
    PicturesMsgID[10] = EZTR_GET_ID_H(PicturesQuestion5);
    PicturesMsgID[11] = EZTR_GET_ID_H(PicturesAnswer5);
    PicturesMsgID[12] = EZTR_GET_ID_H(PicturesQuestion6);
    PicturesMsgID[13] = EZTR_GET_ID_H(PicturesAnswer6);
    PicturesMsgID[14] = EZTR_GET_ID_H(PicturesQuestion7);
    PicturesMsgID[15] = EZTR_GET_ID_H(PicturesAnswer7);
    PicturesMsgID[16] = EZTR_GET_ID_H(PicturesQuestion8);
    PicturesMsgID[17] = EZTR_GET_ID_H(PicturesAnswer8);
    PicturesMsgID[18] = EZTR_GET_ID_H(PicturesQuestion9);
    PicturesMsgID[19] = EZTR_GET_ID_H(PicturesAnswer9);
    PicturesMsgID[20] = EZTR_GET_ID_H(PicturesQuestion10);
    PicturesMsgID[21] = EZTR_GET_ID_H(PicturesAnswer10);
    PicturesMsgID[22] = EZTR_GET_ID_H(PicturesQuestion11);
    PicturesMsgID[23] = EZTR_GET_ID_H(PicturesAnswer11);
    PicturesMsgID[24] = EZTR_GET_ID_H(PicturesQuestion12);
    PicturesMsgID[25] = EZTR_GET_ID_H(PicturesAnswer12);
    PicturesMsgID[26] = EZTR_GET_ID_H(PicturesQuestion13);
    PicturesMsgID[27] = EZTR_GET_ID_H(PicturesAnswer13);
    PicturesMsgID[28] = EZTR_GET_ID_H(PicturesQuestion14);
    PicturesMsgID[29] = EZTR_GET_ID_H(PicturesAnswer14);
    PicturesMsgID[30] = EZTR_GET_ID_H(PicturesQuestion15);
    PicturesMsgID[31] = EZTR_GET_ID_H(PicturesAnswer15);
    PicturesMsgID[32] = EZTR_GET_ID_H(PicturesQuestion16);
    PicturesMsgID[33] = EZTR_GET_ID_H(PicturesAnswer16);
    PicturesMsgID[34] = EZTR_GET_ID_H(PicturesQuestion17);
    PicturesMsgID[35] = EZTR_GET_ID_H(PicturesAnswer17);
    PicturesMsgID[36] = EZTR_GET_ID_H(PicturesQuestion18);
    PicturesMsgID[37] = EZTR_GET_ID_H(PicturesAnswer18);
    PicturesMsgID[38] = EZTR_GET_ID_H(PicturesQuestion19);
    PicturesMsgID[39] = EZTR_GET_ID_H(PicturesAnswer19);
    PicturesMsgID[40] = EZTR_GET_ID_H(PicturesQuestion20);
    PicturesMsgID[41] = EZTR_GET_ID_H(PicturesAnswer20);
    PicturesMsgID[42] = EZTR_GET_ID_H(PicturesQuestion21);
    PicturesMsgID[43] = EZTR_GET_ID_H(PicturesAnswer21);
    PicturesMsgID[44] = EZTR_GET_ID_H(PicturesQuestion22);
    PicturesMsgID[45] = EZTR_GET_ID_H(PicturesAnswer22);
    PicturesMsgID[46] = EZTR_GET_ID_H(PicturesQuestion23);
    PicturesMsgID[47] = EZTR_GET_ID_H(PicturesAnswer23);
    PicturesMsgID[48] = EZTR_GET_ID_H(PicturesQuestion24);
    PicturesMsgID[49] = EZTR_GET_ID_H(PicturesAnswer24);
    PicturesMsgID[50] = EZTR_GET_ID_H(PicturesQuestion25);
    PicturesMsgID[51] = EZTR_GET_ID_H(PicturesAnswer25);
    PicturesMsgID[52] = EZTR_GET_ID_H(PicturesQuestion26);
    PicturesMsgID[53] = EZTR_GET_ID_H(PicturesAnswer26);
    PicturesMsgID[54] = EZTR_GET_ID_H(PicturesQuestion27);
    PicturesMsgID[55] = EZTR_GET_ID_H(PicturesAnswer27);
    PicturesMsgID[56] = EZTR_GET_ID_H(PicturesQuestion28);
    PicturesMsgID[57] = EZTR_GET_ID_H(PicturesAnswer28);
    PicturesMsgID[58] = EZTR_GET_ID_H(PicturesQuestion29);
    PicturesMsgID[59] = EZTR_GET_ID_H(PicturesAnswer29);
}