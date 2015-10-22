#include <allegro.h>
#include <stdio.h>
#include <string.h>
volatile int exit_program;
void fecha_programa() { exit_program = TRUE; }
END_OF_FUNCTION(fecha_programa)

enum {MAINMENU, TELAJOGO, QUESTAO2, QUESTAO3, QUESTAO4, QUESTAO5, QUESTAO6, QUESTAO7, QUESTAO8, QUESTAO9, QUESTAO10, TELAFIM};
int screen_state;
int questao = 1;
int acertos = 0;
int erros = 0;

void init()
{
  allegro_init();
  install_timer();
  install_keyboard();
  install_mouse();
  set_color_depth(32);
  install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT,NULL);
  if((set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1280, 640, 0, 0)) < 0){
        printf("falha no video");
  }
  set_window_title("Jogo de Inglês");

  exit_program = FALSE;
  LOCK_FUNCTION(fecha_programa);
  LOCK_VARIABLE(exit_program);
  set_close_button_callback(fecha_programa);

  screen_state = MAINMENU;
}

void mainmenu()
{
    int exit_screen = FALSE;
  ///BITMAPS
  BITMAP* buffer;
  BITMAP* fundo;
  buffer = create_bitmap(SCREEN_W, SCREEN_H);
  fundo = load_bitmap("fundo1.bmp", NULL);
   BITMAP* botaoNJ = load_bitmap("NJ.bmp", NULL);
   BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);
   BITMAP* botaoInterro= load_bitmap("interro.bmp", NULL);
   BITMAP* cursor=load_bitmap("cursor.bmp",NULL);

    ///SONS
   // SAMPLE *wave =load_sample("som.wav");
    MIDI *midi =load_midi("midi.mid");
    play_midi(midi, TRUE);

  ///GAME LOOP
  while(!exit_program && !exit_screen)
  {
     //INPUT
     if(key[KEY_ESC])
      fecha_programa();
     //UPDATE

     //DRAW
     set_trans_blender(255, 255, 255, 128);

     draw_sprite(buffer, fundo,0, 0);
     draw_sprite_ex(buffer, botaoNJ, 350, 430, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
     draw_sprite_ex(buffer, botaoSair,650,430, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
     draw_sprite_ex(buffer, botaoInterro,515,100, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
     draw_sprite(buffer,cursor,mouse_x,mouse_y);

///BOTOES CLICK
     if(mouse_x >350 && mouse_x <600
        && mouse_y>430 && mouse_y < 511 )
     {
        draw_sprite_ex(buffer, botaoNJ,350,425, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1)
         {
             exit_screen = TRUE;
             screen_state = TELAJOGO;
         }
     }
     if(mouse_x >650 && mouse_x <900
        && mouse_y>430 && mouse_y < 511 )
     {
        draw_sprite_ex(buffer, botaoSair,650,425, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             fecha_programa();
         }
     }

     draw_sprite(screen, buffer, 0, 0);
     clear(buffer);
  }

  ///FINALIZA��O
  destroy_bitmap(buffer);
  destroy_bitmap(fundo);
  destroy_bitmap(botaoNJ);
//  destroy_sample(wave);
  destroy_bitmap(botaoSair);
  destroy_bitmap(botaoInterro);
  destroy_bitmap(cursor);
  destroy_midi(midi);

}

void telajogo ()
{
    int exit_screen= FALSE;

    ///BITMAPS
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* fundo=load_bitmap("lousa.bmp", NULL);
    BITMAP* caneta=load_bitmap("caneta.bmp", NULL);
    BITMAP* a1=load_bitmap("1pencil.bmp", NULL);
    BITMAP* a2=load_bitmap("1pen.bmp", NULL);
    BITMAP* a3=load_bitmap("1book.bmp", NULL);
    BITMAP* a4=load_bitmap("1case.bmp",NULL);
    BITMAP* ab1=load_bitmap("ab1.bmp", NULL);
    BITMAP* ab2=load_bitmap("ab2.bmp", NULL);
    BITMAP* ab3=load_bitmap("ab3.bmp", NULL);
    BITMAP* ab4=load_bitmap("ab4.bmp",NULL);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);

    //GAMELOPPING
    while(!exit_program && !exit_screen)
          {
                    //INPUT
                    if(key[KEY_ESC])
                        fecha_programa();
                    //UPDATE

                    //DESENHAR
                    draw_sprite(buffer,fundo,0,0);
                    textout_centre_ex(buffer,font,"QUAL ALTERNATIVA ESTA CORRETA ?",SCREEN_W/2,SCREEN_H/2, makecol(255,255,255), -1);
                    draw_sprite_ex(buffer,caneta,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a1,400,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a2,600,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a3,400,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a4,600,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,botaoSair,900,500,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite(buffer,cursor,mouse_x,mouse_y);

                    ///BOTOES CLICK
     if(mouse_x >400 && mouse_x <599
        && mouse_y>370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab1,400,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
            screen_state = QUESTAO2;
            exit_screen = TRUE;
             erros = erros + 1;
         }

     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab2,600,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ACERTOU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO2;
             acertos = acertos + 1;
         }
     }
     else if(mouse_x>400 && mouse_x <599
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab3,400,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO2;
             erros = erros + 1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab4,600,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO2;
             erros = erros + 1;
         }
     }
     else if(mouse_x>900 && mouse_x <1100
             && mouse_y> 500 && mouse_y < 600 )
     {
        draw_sprite_ex(buffer, botaoSair,900,510, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
            fecha_programa();
         }
     }
        draw_sprite(screen,buffer, 0, 0);
        clear_to_color(buffer,makecol(203,114,70));

          }
          //FINALIZACAO
          destroy_bitmap(buffer);
          destroy_bitmap(fundo);
          destroy_bitmap(a1);
          destroy_bitmap(a2);
          destroy_bitmap(a3);
          destroy_bitmap(a4);
          destroy_bitmap(ab1);
          destroy_bitmap(ab2);
          destroy_bitmap(ab3);
          destroy_bitmap(ab4);
          destroy_bitmap(cursor);
          destroy_bitmap(botaoSair);
}

void questao2 ()
{
    int exit_screen= FALSE;
    questao = questao + 1;
    ///BITMAPS
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* fundo=load_bitmap("lousa.bmp", NULL);
    BITMAP* caneta=load_bitmap("chaves.bmp", NULL);
    BITMAP* a1=load_bitmap("2a.bmp", NULL);
    BITMAP* a2=load_bitmap("2b.bmp", NULL);
    BITMAP* a3=load_bitmap("2c.bmp", NULL);
    BITMAP* a4=load_bitmap("2d.bmp",NULL);
    BITMAP* ab1=load_bitmap("2aH.bmp", NULL);
    BITMAP* ab2=load_bitmap("2bH.bmp", NULL);
    BITMAP* ab3=load_bitmap("2cH.bmp", NULL);
    BITMAP* ab4=load_bitmap("2dH.bmp",NULL);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);

    //GAMELOPPING
    while(!exit_program && !exit_screen)
          {
                    //INPUT
                    if(key[KEY_ESC])
                        fecha_programa();
                    //UPDATE

                    //DESENHAR
                    draw_sprite(buffer,fundo,0,0);
                    textout_centre_ex(buffer,font,"QUAL ALTERNATIVA ESTA CORRETA ?",SCREEN_W/2,SCREEN_H/2, makecol(255,255,255), -1);
                    draw_sprite_ex(buffer,caneta,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a1,400,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a2,600,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a3,400,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a4,600,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,botaoSair,900,500,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite(buffer,cursor,mouse_x,mouse_y);

                    ///BOTOES CLICK
     if(mouse_x >400 && mouse_x <599
        && mouse_y>370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab1,400,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             screen_state = QUESTAO3;
             exit_screen = TRUE;
             erros = erros + 1;
         }

     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab2,600,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ACERTOU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO3;
             acertos = acertos + 1;
         }
     }
     else if(mouse_x>400 && mouse_x <599
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab3,400,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO3;
             erros = erros + 1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab4,600,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO3;
             erros = erros + 1;
         }
     }
     else if(mouse_x>900 && mouse_x <1100
             && mouse_y> 500 && mouse_y < 600 )
     {
        draw_sprite_ex(buffer, botaoSair,900,510, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
            fecha_programa();
         }
     }
        draw_sprite(screen,buffer, 0, 0);
        clear_to_color(buffer,makecol(203,114,70));
          }
          //FINALIZACAO
          destroy_bitmap(buffer);
          destroy_bitmap(fundo);
          destroy_bitmap(a1);
          destroy_bitmap(a2);
          destroy_bitmap(a3);
          destroy_bitmap(a4);
          destroy_bitmap(ab1);
          destroy_bitmap(ab2);
          destroy_bitmap(ab3);
          destroy_bitmap(ab4);
          destroy_bitmap(cursor);
          destroy_bitmap(botaoSair);
}

void questao3 ()
{
    int exit_screen= FALSE;
    questao = questao + 1;
    ///BITMAPS
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* fundo=load_bitmap("lousa.bmp", NULL);
    BITMAP* caneta=load_bitmap("caderno.bmp", NULL);
    BITMAP* a1=load_bitmap("3a.bmp", NULL);
    BITMAP* a2=load_bitmap("3b.bmp", NULL);
    BITMAP* a3=load_bitmap("3c.bmp", NULL);
    BITMAP* a4=load_bitmap("3d.bmp",NULL);
    BITMAP* ab1=load_bitmap("3aH.bmp", NULL);
    BITMAP* ab2=load_bitmap("3bH.bmp", NULL);
    BITMAP* ab3=load_bitmap("3cH.bmp", NULL);
    BITMAP* ab4=load_bitmap("3dH.bmp",NULL);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);

    //GAMELOPPING
    while(!exit_program && !exit_screen)
          {
                    //INPUT
                    if(key[KEY_ESC])
                        fecha_programa();
                    //UPDATE

                    //DESENHAR
                    draw_sprite(buffer,fundo,0,0);
                    textout_centre_ex(buffer,font,"QUAL ALTERNATIVA ESTA CORRETA ?",SCREEN_W/2,SCREEN_H/2, makecol(255,255,255), -1);
                    draw_sprite_ex(buffer,caneta,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a1,400,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a2,600,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a3,400,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a4,600,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,botaoSair,900,500,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite(buffer,cursor,mouse_x,mouse_y);

                    ///BOTOES CLICK
     if(mouse_x >400 && mouse_x <599
        && mouse_y>370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab1,400,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
            exit_screen = TRUE;
            screen_state = QUESTAO4;
             erros = erros + 1;
         }

     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab2,600,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO4;
             erros = erros + 1;
         }
     }
     else if(mouse_x>400 && mouse_x <599
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab3,400,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO4;
             erros = erros + 1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab4,600,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ACERTOU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO4;
             acertos = acertos + 1;
         }
     }
     else if(mouse_x>900 && mouse_x <1100
             && mouse_y> 500 && mouse_y < 600 )
     {
        draw_sprite_ex(buffer, botaoSair,900,510, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
            fecha_programa();
         }
     }
        draw_sprite(screen,buffer, 0, 0);
        clear_to_color(buffer,makecol(203,114,70));

          }
          //FINALIZACAO
          destroy_bitmap(buffer);
          destroy_bitmap(fundo);
          destroy_bitmap(a1);
          destroy_bitmap(a2);
          destroy_bitmap(a3);
          destroy_bitmap(a4);
          destroy_bitmap(ab1);
          destroy_bitmap(ab2);
          destroy_bitmap(ab3);
          destroy_bitmap(ab4);
          destroy_bitmap(cursor);
          destroy_bitmap(botaoSair);
}

void questao4 ()
{
    int exit_screen= FALSE;
    questao = questao + 1;
    ///BITMAPS
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* fundo=load_bitmap("lousa.bmp", NULL);
    BITMAP* caneta=load_bitmap("sofa.bmp", NULL);
    BITMAP* a1=load_bitmap("4a.bmp", NULL);
    BITMAP* a2=load_bitmap("4b.bmp", NULL);
    BITMAP* a3=load_bitmap("4c.bmp", NULL);
    BITMAP* a4=load_bitmap("4d.bmp",NULL);
    BITMAP* ab1=load_bitmap("4aH.bmp", NULL);
    BITMAP* ab2=load_bitmap("4bH.bmp", NULL);
    BITMAP* ab3=load_bitmap("4cH.bmp", NULL);
    BITMAP* ab4=load_bitmap("4dH.bmp",NULL);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);

    //GAMELOPPING
    while(!exit_program && !exit_screen)
          {
                    //INPUT
                    if(key[KEY_ESC])
                        fecha_programa();
                    //UPDATE

                    //DESENHAR
                    draw_sprite(buffer,fundo,0,0);
                    textout_centre_ex(buffer,font,"QUAL ALTERNATIVA ESTA CORRETA ?",SCREEN_W/2,SCREEN_H/2, makecol(255,255,255), -1);
                    draw_sprite_ex(buffer,caneta,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a1,400,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a2,600,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a3,400,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a4,600,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,botaoSair,900,500,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite(buffer,cursor,mouse_x,mouse_y);

                    ///BOTOES CLICK
     if(mouse_x >400 && mouse_x <599
        && mouse_y>370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab1,400,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ACERTOU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO5;
             acertos = acertos + 1;
         }

     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab2,600,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO5;
             erros = erros + 1;
         }
     }
     else if(mouse_x>400 && mouse_x <599
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab3,400,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO5;
             erros = erros + 1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab4,600,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO5;
             erros = erros + 1;
         }
     }
     else if(mouse_x>900 && mouse_x <1100
             && mouse_y> 500 && mouse_y < 600 )
     {
        draw_sprite_ex(buffer, botaoSair,900,510, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
            fecha_programa();
         }
     }
        draw_sprite(screen,buffer, 0, 0);
        clear_to_color(buffer,makecol(203,114,70));

          }
          //FINALIZACAO
          destroy_bitmap(buffer);
          destroy_bitmap(fundo);
          destroy_bitmap(a1);
          destroy_bitmap(a2);
          destroy_bitmap(a3);
          destroy_bitmap(a4);
          destroy_bitmap(ab1);
          destroy_bitmap(ab2);
          destroy_bitmap(ab3);
          destroy_bitmap(ab4);
          destroy_bitmap(cursor);
          destroy_bitmap(botaoSair);
}

void questao5 ()
{
    int exit_screen= FALSE;
    questao = questao + 1;
    ///BITMAPS
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* fundo=load_bitmap("lousa.bmp", NULL);
    BITMAP* caneta=load_bitmap("faca.bmp", NULL);
    BITMAP* a1=load_bitmap("5a.bmp", NULL);
    BITMAP* a2=load_bitmap("5b.bmp", NULL);
    BITMAP* a3=load_bitmap("5c.bmp", NULL);
    BITMAP* a4=load_bitmap("5d.bmp",NULL);
    BITMAP* ab1=load_bitmap("5aH.bmp", NULL);
    BITMAP* ab2=load_bitmap("5bH.bmp", NULL);
    BITMAP* ab3=load_bitmap("5cH.bmp", NULL);
    BITMAP* ab4=load_bitmap("5dH.bmp",NULL);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);


    //GAMELOPPING
    while(!exit_program && !exit_screen)
          {
                    //INPUT
                    if(key[KEY_ESC])
                        fecha_programa();
                    //UPDATE

                    //DESENHAR
                    draw_sprite(buffer,fundo,0,0);
                    textout_centre_ex(buffer,font,"QUAL ALTERNATIVA ESTA CORRETA ?",SCREEN_W/2,SCREEN_H/2, makecol(255,255,255), -1);
                    draw_sprite_ex(buffer,caneta,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a1,400,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a2,600,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a3,400,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a4,600,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,botaoSair,900,500,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite(buffer,cursor,mouse_x,mouse_y);

                    ///BOTOES CLICK
     if(mouse_x >400 && mouse_x <599
        && mouse_y>370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab1,400,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO6;
             erros = erros + 1;
         }

     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab2,600,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ACERTOU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO6;
             acertos = acertos + 1;
         }
     }
     else if(mouse_x>400 && mouse_x <599
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab3,400,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO6;
             erros = erros + 1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab4,600,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO6;
             erros = erros + 1;
         }
     }
     else if(mouse_x>900 && mouse_x <1100
             && mouse_y> 500 && mouse_y < 600 )
     {
        draw_sprite_ex(buffer, botaoSair,900,510, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
            fecha_programa();
         }
     }
        draw_sprite(screen,buffer, 0, 0);
        clear_to_color(buffer,makecol(203,114,70));

          }
          //FINALIZACAO
          destroy_bitmap(buffer);
          destroy_bitmap(fundo);
          destroy_bitmap(a1);
          destroy_bitmap(a2);
          destroy_bitmap(a3);
          destroy_bitmap(a4);
          destroy_bitmap(ab1);
          destroy_bitmap(ab2);
          destroy_bitmap(ab3);
          destroy_bitmap(ab4);
          destroy_bitmap(cursor);
          destroy_bitmap(botaoSair);
}

void questao6 ()
{
    int exit_screen= FALSE;
    questao = questao + 1;
    ///BITMAPS
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* fundo=load_bitmap("lousa.bmp", NULL);
    BITMAP* caneta=load_bitmap("elefante.bmp", NULL);
    BITMAP* a1=load_bitmap("6a.bmp", NULL);
    BITMAP* a2=load_bitmap("6b.bmp", NULL);
    BITMAP* a3=load_bitmap("6c.bmp", NULL);
    BITMAP* a4=load_bitmap("6d.bmp",NULL);
    BITMAP* ab1=load_bitmap("6aH.bmp", NULL);
    BITMAP* ab2=load_bitmap("6bH.bmp", NULL);
    BITMAP* ab3=load_bitmap("6cH.bmp", NULL);
    BITMAP* ab4=load_bitmap("6dH.bmp",NULL);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);

    //GAMELOPPING
    while(!exit_program && !exit_screen)
          {
                    //INPUT
                    if(key[KEY_ESC])
                        fecha_programa();
                    //UPDATE

                    //DESENHAR
                    draw_sprite(buffer,fundo,0,0);
                    textout_centre_ex(buffer,font,"QUAL ALTERNATIVA ESTA CORRETA ?",SCREEN_W/2,SCREEN_H/2, makecol(255,255,255), -1);
                    draw_sprite_ex(buffer,caneta,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a1,400,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a2,600,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a3,400,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a4,600,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,botaoSair,900,500,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite(buffer,cursor,mouse_x,mouse_y);

                    ///BOTOES CLICK
     if(mouse_x >400 && mouse_x <599
        && mouse_y>370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab1,400,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO7;
             erros = erros + 1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab2,600,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO7;
             erros = erros + 1;
         }
     }
     else if(mouse_x>400 && mouse_x <599
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab3,400,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ACERTOU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO7;
             acertos = acertos + 1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab4,600,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO7;
             erros = erros + 1;
         }
     }
     else if(mouse_x>900 && mouse_x <1100
             && mouse_y> 500 && mouse_y < 600 )
     {
        draw_sprite_ex(buffer, botaoSair,900,510, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
            fecha_programa();
         }
     }
        draw_sprite(screen,buffer, 0, 0);
        clear_to_color(buffer,makecol(203,114,70));

          }
          //FINALIZACAO
          destroy_bitmap(buffer);
          destroy_bitmap(fundo);
          destroy_bitmap(a1);
          destroy_bitmap(a2);
          destroy_bitmap(a3);
          destroy_bitmap(a4);
          destroy_bitmap(ab1);
          destroy_bitmap(ab2);
          destroy_bitmap(ab3);
          destroy_bitmap(ab4);
          destroy_bitmap(cursor);
          destroy_bitmap(botaoSair);
}

void questao7 ()
{
    int exit_screen= FALSE;
    questao = questao + 1;
    ///BITMAPS
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* fundo=load_bitmap("lousa.bmp", NULL);
    BITMAP* caneta=load_bitmap("cachecol.bmp", NULL);
    BITMAP* a1=load_bitmap("7a.bmp", NULL);
    BITMAP* a2=load_bitmap("7b.bmp", NULL);
    BITMAP* a3=load_bitmap("7c.bmp", NULL);
    BITMAP* a4=load_bitmap("7d.bmp",NULL);
    BITMAP* ab1=load_bitmap("7aH.bmp", NULL);
    BITMAP* ab2=load_bitmap("7bH.bmp", NULL);
    BITMAP* ab3=load_bitmap("7cH.bmp", NULL);
    BITMAP* ab4=load_bitmap("7dH.bmp",NULL);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);

    //GAMELOPPING
    while(!exit_program && !exit_screen)
          {
                    //INPUT
                    if(key[KEY_ESC])
                        fecha_programa();
                    //UPDATE

                    //DESENHAR
                    draw_sprite(buffer,fundo,0,0);
                    textout_centre_ex(buffer,font,"QUAL ALTERNATIVA ESTA CORRETA ?",SCREEN_W/2,SCREEN_H/2, makecol(255,255,255), -1);
                    draw_sprite_ex(buffer,caneta,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a1,400,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a2,600,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a3,400,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a4,600,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,botaoSair,900,500,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite(buffer,cursor,mouse_x,mouse_y);

                    ///BOTOES CLICK
     if(mouse_x >400 && mouse_x <599
        && mouse_y>370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab1,400,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO8;
             erros = erros + 1;
         }

     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab2,600,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO8;
             erros = erros + 1;
         }
     }
     else if(mouse_x>400 && mouse_x <599
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab3,400,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO8;
             erros = erros + 1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab4,600,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ACERTOU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO8;
             acertos = acertos + 1;
         }
     }
     else if(mouse_x>900 && mouse_x <1100
             && mouse_y> 500 && mouse_y < 600 )
     {
        draw_sprite_ex(buffer, botaoSair,900,510, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
            fecha_programa();
         }
     }
        draw_sprite(screen,buffer, 0, 0);
        clear_to_color(buffer,makecol(203,114,70));

          }
          //FINALIZACAO
          destroy_bitmap(buffer);
          destroy_bitmap(fundo);
          destroy_bitmap(a1);
          destroy_bitmap(a2);
          destroy_bitmap(a3);
          destroy_bitmap(a4);
          destroy_bitmap(ab1);
          destroy_bitmap(ab2);
          destroy_bitmap(ab3);
          destroy_bitmap(ab4);
          destroy_bitmap(cursor);
          destroy_bitmap(botaoSair);
}

void questao8 ()
{
    int exit_screen= FALSE;
    questao = questao + 1;
    ///BITMAPS
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* fundo=load_bitmap("lousa.bmp", NULL);
    BITMAP* caneta=load_bitmap("aguia.bmp", NULL);
    BITMAP* a1=load_bitmap("8a.bmp", NULL);
    BITMAP* a2=load_bitmap("8b.bmp", NULL);
    BITMAP* a3=load_bitmap("8c.bmp", NULL);
    BITMAP* a4=load_bitmap("8d.bmp",NULL);
    BITMAP* ab1=load_bitmap("8aH.bmp", NULL);
    BITMAP* ab2=load_bitmap("8bH.bmp", NULL);
    BITMAP* ab3=load_bitmap("8cH.bmp", NULL);
    BITMAP* ab4=load_bitmap("8dH.bmp",NULL);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);

    //GAMELOPPING
    while(!exit_program && !exit_screen)
          {
                    //INPUT
                    if(key[KEY_ESC])
                        fecha_programa();
                    //UPDATE

                    //DESENHAR
                    draw_sprite(buffer,fundo,0,0);
                    textout_centre_ex(buffer,font,"QUAL ALTERNATIVA ESTA CORRETA ?",SCREEN_W/2,SCREEN_H/2, makecol(255,255,255), -1);
                    draw_sprite_ex(buffer,caneta,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a1,400,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a2,600,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a3,400,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a4,600,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,botaoSair,900,500,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite(buffer,cursor,mouse_x,mouse_y);

                    ///BOTOES CLICK
     if(mouse_x >400 && mouse_x <599
        && mouse_y>370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab1,400,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO9;
             erros = erros + 1;
         }

     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab2,600,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ACERTOU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO9;
             acertos = acertos + 1;
         }
     }
     else if(mouse_x>400 && mouse_x <599
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab3,400,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO9;
             erros = erros + 1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab4,600,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO9;
             erros = erros + 1;
         }
     }
     else if(mouse_x>900 && mouse_x <1100
             && mouse_y> 500 && mouse_y < 600 )
     {
        draw_sprite_ex(buffer, botaoSair,900,510, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
            fecha_programa();
         }
     }
        draw_sprite(screen,buffer, 0, 0);
        clear_to_color(buffer,makecol(203,114,70));

          }
          //FINALIZACAO
          destroy_bitmap(buffer);
          destroy_bitmap(fundo);
          destroy_bitmap(a1);
          destroy_bitmap(a2);
          destroy_bitmap(a3);
          destroy_bitmap(a4);
          destroy_bitmap(ab1);
          destroy_bitmap(ab2);
          destroy_bitmap(ab3);
          destroy_bitmap(ab4);
          destroy_bitmap(cursor);
          destroy_bitmap(botaoSair);
}

void questao9 ()
{
    int exit_screen= FALSE;
    questao = questao + 1;
    ///BITMAPS
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* fundo=load_bitmap("lousa.bmp", NULL);
    BITMAP* caneta=load_bitmap("piscina.bmp", NULL);
    BITMAP* a1=load_bitmap("9a.bmp", NULL);
    BITMAP* a2=load_bitmap("9b.bmp", NULL);
    BITMAP* a3=load_bitmap("9c.bmp", NULL);
    BITMAP* a4=load_bitmap("9d.bmp",NULL);
    BITMAP* ab1=load_bitmap("9aH.bmp", NULL);
    BITMAP* ab2=load_bitmap("9bH.bmp", NULL);
    BITMAP* ab3=load_bitmap("9cH.bmp", NULL);
    BITMAP* ab4=load_bitmap("9dH.bmp",NULL);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);

    //GAMELOPPING
    while(!exit_program && !exit_screen)
          {
                    //INPUT
                    if(key[KEY_ESC])
                        fecha_programa();
                    //UPDATE

                    //DESENHAR
                    draw_sprite(buffer,fundo,0,0);
                    textout_centre_ex(buffer,font,"QUAL ALTERNATIVA ESTA CORRETA ?",SCREEN_W/2,SCREEN_H/2, makecol(255,255,255), -1);
                    draw_sprite_ex(buffer,caneta,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a1,400,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a2,600,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a3,400,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a4,600,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,botaoSair,900,500,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite(buffer,cursor,mouse_x,mouse_y);

                    ///BOTOES CLICK
     if(mouse_x >400 && mouse_x <599
        && mouse_y>370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab1,400,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ACERTOU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO10;
             acertos = acertos + 1;
         }

     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab2,600,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO10;
             erros = erros + 1;
         }
     }
     else if(mouse_x>400 && mouse_x <599
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab3,400,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO10;
             erros = erros + 1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab4,600,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = QUESTAO10;
             erros = erros + 1;
         }
     }
     else if(mouse_x>900 && mouse_x <1100
             && mouse_y> 500 && mouse_y < 600 )
     {
        draw_sprite_ex(buffer, botaoSair,900,510, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
            fecha_programa();
         }
     }
        draw_sprite(screen,buffer, 0, 0);
        clear_to_color(buffer,makecol(203,114,70));
          }
          //FINALIZACAO
          destroy_bitmap(buffer);
          destroy_bitmap(fundo);
          destroy_bitmap(a1);
          destroy_bitmap(a2);
          destroy_bitmap(a3);
          destroy_bitmap(a4);
          destroy_bitmap(ab1);
          destroy_bitmap(ab2);
          destroy_bitmap(ab3);
          destroy_bitmap(ab4);
          destroy_bitmap(cursor);
          destroy_bitmap(botaoSair);
}

void questao10 ()
{
    int exit_screen= FALSE;
    questao = questao + 1;
    ///BITMAPS
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* fundo=load_bitmap("lousa.bmp", NULL);
    BITMAP* caneta=load_bitmap("trampolim.bmp", NULL);
    BITMAP* a1=load_bitmap("10a.bmp", NULL);
    BITMAP* a2=load_bitmap("10b.bmp", NULL);
    BITMAP* a3=load_bitmap("10c.bmp", NULL);
    BITMAP* a4=load_bitmap("10d.bmp",NULL);
    BITMAP* ab1=load_bitmap("10aH.bmp", NULL);
    BITMAP* ab2=load_bitmap("10bH.bmp", NULL);
    BITMAP* ab3=load_bitmap("10cH.bmp", NULL);
    BITMAP* ab4=load_bitmap("10dH.bmp",NULL);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* botaoSair= load_bitmap("sair.bmp", NULL);
    //GAMELOPPING
    while(!exit_program && !exit_screen)
          {
                    //INPUT
                    if(key[KEY_ESC])
                        fecha_programa();
                    //UPDATE

                    //DESENHAR
                    draw_sprite(buffer,fundo,0,0);
                    textout_centre_ex(buffer,font,"QUAL ALTERNATIVA ESTA CORRETA ?",SCREEN_W/2,SCREEN_H/2, makecol(255,255,255), -1);
                    draw_sprite_ex(buffer,caneta,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a1,400,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a2,600,370,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a3,400,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,a4,600,480,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite_ex(buffer,botaoSair,900,500,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
                    draw_sprite(buffer,cursor,mouse_x,mouse_y);

                    ///BOTOES CLICK
     if(mouse_x >400 && mouse_x <599
        && mouse_y>370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab1,400,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = TELAFIM;
             erros = erros +1;

         }

     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 370 && mouse_y < 479 )
     {
        draw_sprite_ex(buffer, ab2,600,370, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
            exit_screen = TRUE;
            screen_state = TELAFIM;
             erros = erros +1;
         }
     }
     else if(mouse_x>400 && mouse_x <599
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab3,400,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);

         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ERROU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             screen_state = TELAFIM;
             exit_screen = TRUE;
             erros = erros +1;
         }
     }
     else if(mouse_x>600 && mouse_x <850
             && mouse_y> 480 && mouse_y < 566 )
     {
        draw_sprite_ex(buffer, ab4,600,480, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             textout_centre_ex(buffer,font,"VOCÊ ACERTOU",SCREEN_W/2,SCREEN_H/1.8, makecol (255,255,255), -1);
             exit_screen = TRUE;
             screen_state = TELAFIM;
             acertos = acertos + 1;
         }
     }
     else if(mouse_x>900 && mouse_x <1100
             && mouse_y> 500 && mouse_y < 600 )
     {
        draw_sprite_ex(buffer, botaoSair,900,510, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
            fecha_programa();
         }
     }
        draw_sprite(screen,buffer, 0, 0);
        clear_to_color(buffer,makecol(203,114,70));
          }
          //FINALIZACAO
          destroy_bitmap(buffer);
          destroy_bitmap(fundo);
          destroy_bitmap(a1);
          destroy_bitmap(a2);
          destroy_bitmap(a3);
          destroy_bitmap(a4);
          destroy_bitmap(ab1);
          destroy_bitmap(ab2);
          destroy_bitmap(ab3);
          destroy_bitmap(ab4);
          destroy_bitmap(cursor);
          destroy_bitmap(botaoSair);
}

void gameOver()
{
    char aux[2];
	itoa(questao, aux, 10);
	char numQuestao[50] = "Número de Questões: ";
	strcat(numQuestao, aux);

	char aux2[2];
	itoa(acertos, aux2, 10);
	char numAcertos[50] = "Número de Acertos: ";
	strcat(numAcertos, aux2);

	char aux3[2];
	itoa(erros, aux3, 10);
	char numErros[50] = "Número de Erros: ";
	strcat(numErros, aux3);


    int exit_screen = FALSE;
  ///BITMAPS
  BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
  BITMAP* fundo = load_bitmap("lousa.bmp", NULL);
  BITMAP* botaoSair = load_bitmap("sair.bmp", NULL);
  BITMAP* cursor = load_bitmap("cursor.bmp",NULL);
  BITMAP* gameover=load_bitmap("gameover.bmp", NULL);
    ///SONS
    MIDI *midi = load_midi("midi.mid");
    play_midi(midi, TRUE);

  ///GAME LOOP
  while(!exit_program && !exit_screen)
  {
     //INPUT
     if(key[KEY_ESC])
      fecha_programa();
     //UPDATE


     //DRAW
     set_trans_blender(255, 255, 255, 128);

     draw_sprite(buffer, fundo,0, 0);
     draw_sprite_ex(buffer,gameover,491,60,DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
     textout_centre_ex(buffer,font,numQuestao,550,340, makecol (255,255,255), -1);
     textout_centre_ex(buffer,font,numAcertos,550,380, makecol (255,255,255), -1);
     textout_centre_ex(buffer,font,numErros,550,410, makecol (255,255,255), -1);
     draw_sprite_ex(buffer, botaoSair,650,430, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
     draw_sprite(buffer,cursor,mouse_x,mouse_y);
     draw_sprite(screen, buffer, 0, 0);




//Botão Sair
        if(mouse_x >650 && mouse_x <900
        && mouse_y>430 && mouse_y < 511 )
     {
        draw_sprite_ex(buffer, botaoSair,650,425, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);
         draw_sprite(buffer,cursor,mouse_x,mouse_y);
         if(mouse_b ==1 )
         {
             fecha_programa();
         }
     }

     clear(buffer);
  }

  ///FINALIZA��O
  destroy_bitmap(buffer);
  destroy_bitmap(fundo);
  destroy_bitmap(botaoSair);
  destroy_bitmap(cursor);
  destroy_bitmap(gameover);
  destroy_midi(midi);
}

int main()
{
 init();

 while(!exit_program)
 {
    if(screen_state == MAINMENU)
        mainmenu();
    else if(erros <= 3)
    {
        if(screen_state == TELAJOGO)
            telajogo();
        else if(screen_state == QUESTAO2)
            questao2();
        else if(screen_state == QUESTAO3)
            questao3();
        else if(screen_state == QUESTAO4)
            questao4();
        else if(screen_state == QUESTAO5)
            questao5();
        else if(screen_state == QUESTAO6)
            questao6();
        else if(screen_state == QUESTAO7)
            questao7();
        else if(screen_state ==QUESTAO8)
            questao8();
        else if(screen_state == QUESTAO9)
            questao9();
        else if(screen_state == QUESTAO10)
            questao10();
        else if(screen_state == TELAFIM)
            gameOver();
    }
    else
        gameOver();
 }
    return 0;
}
END_OF_MAIN();
