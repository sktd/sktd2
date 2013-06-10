#include "map.h"
#include <fstream>
#include <string>
#include "mob1.h"
#include "tower1.h"
#include "tower2.h"
#include "Tower3.h"

map::map::map(void)
{
	
	load_level("lvl.txt");
	for(int i=0;;i++){
		if(track[i].get_type()==1){
			chosen=&track[i];
			break;
		}
	}
	for(int i=0;;i++){
		if(track[i].get_type()==3){
			start_x=track[i].get_pos_x();
			start_y=track[i].get_pos_y();
			break;
		}
	}
	for(int i=0;;i++){
		if(track[i].get_type()==4){
			end_x=track[i].get_pos_x();
			end_y=track[i].get_pos_y();
			break;
		}
	}
}


map::map::~map(void)
{
}

void map::map::begin_wave(double px, double py, std::string s, double vel, double hlth, int wrth, int hm)
{
	while(hm--){
		mob *wsk=new mob(px, py, s, vel, hlth, wrth, 0);
		mobs.push_back(wsk);
	}
}

void map::map::end_wave()
{

}

//bool map::map::load_level(const char *filename){
//	*FILE *f = fopen(filename, "r");
//	if(!f){ 
//		fprintf(stderr, "error: could not open map file \"%s\"\n", filename);
//		return false;
//	}
//
//	int x=100;
//	int y=100;
//	for(int j = 0; j < width; j++) {
//		char line[64];
//		fgets(line, sizeof(line), f);
//		if(feof(f)){ 
//			fprintf(stderr, "error: unexpected end of file \"%s\"\n", filename);
//			fclose(f);
//			return false;
//		}
//		tile *wsk;
//
//		for(int i = 0; i < height; i++) {
//			switch(line[i]) {
//			case ' ':	
//				wsk=new tile(x,y,"tor1.bmp",MAP_NONE);
//				track[j][i] = *wsk; 
//				x+=30;
//				break;
//			case '#': 	
//				wsk=new tile(x,y,"tor1.bmp",MAP_ROAD);
//				track[j][i] = *wsk; 
//				x+=30;
//				break;
//			case 'X': 	
//				wsk=new tile(x,y,"tor1.bmp",MAP_GRASS);
//				track[j][i] = *wsk; 
//				x+=30;
//
//				break;
//			case 'B': 	
//				wsk=new tile(x,y,"tor1.bmp",MAP_BUILDABLE);
//				track[j][i] = *wsk; 
//				x+=30;
//				break;
//			default:
//				fprintf(stderr, "error: unknown map character \"%c\" in \"%s\"\n",
//				line[i], filename);
//				fclose(f);
//				return false;
//				break;
//			}
//		}
//		y+=40;
//		x=100;
//	}
// 
//	printf("info: loaded map \"%s\"\n", filename);
//
//	fclose(f);
//	return true;*/
//
//	std::fstream file;
//	file.open(filename, std::ios::in);
//	if(file.good()==true){
//
//	}
//	else
//	{
//
//	}
//}

void map::map::load_level(std::string filename){
	std::fstream file;
	file.open(filename.c_str(), std::ios::in);
	if(file.good()==true){
		std::string tmp;
		int tiles=0;
		int x=100;
		int y=100;
		while(!file.eof()){
			std::getline(file, tmp);
			for(int i=0;i<tmp.size();i++){
				switch(tmp[i]){
				case 'B':
					{
					tile *wsk=new tile(x,y,"Grafika/budowa.png",1);
					track[tiles]=*wsk;
					tiles++;
					break;
					}
				case 'X':
					{
					tile *wsk=new tile(x,y,"Grafika/droga.png",2);
					track[tiles]=*wsk;
					tiles++;
					track2[x][y]=1;
					break;
					}
				case 'S'://pierwszy tile trasy po ktorej ida moby
					{
					tile *wsk=new tile(x,y,"Grafika/start.png", 3);
					track[tiles]=*wsk;
					tiles++;
					track2[x][y]=1;
					break;
					}
				case 'E'://ostatni tile trasy po ktorej ida moby
					{
					tile *wsk=new tile(x,y,"Grafika/koniec.png", 4);
					track[tiles]=*wsk;
					tiles++;
					track2[x][y]=1;
					break;
					}

				}
				x+=30;
			}
			x=100;
			y+=30;
		}
		file.close();
	}
	else
	{
	}
}

void map::map::build_tower(std::string s, double spd, int cst, engine::player_console &console, int which_tower){
	if(chosen!=NULL){
		tower *wsk;
		switch ( which_tower ) {
		case 1:
			wsk=new tower1((*chosen).get_pos_x(), (*chosen).get_pos_y(), s, spd, cst);
			break;
		case 2:
			wsk=new tower2((*chosen).get_pos_x(), (*chosen).get_pos_y(), s, spd, cst, 1);
			break;
		case 3:
			wsk=new Tower3((*chosen).get_pos_x(), (*chosen).get_pos_y(), s, spd, cst);
			break;
		}
		if(console.get_resources()>=(*wsk).get_cost()){
			towers.push_back(wsk);
			(*chosen).set_type(0);
			move_chosen_r();
			console.subtract_resources((*wsk).get_cost());
		}
	}
}

void map::map::display(sf::RenderWindow &win, engine::player_console &console){

	for(int i=0;i<width*height;i++){
		if(track[i].get_type()!=0)
			track[i].draw(win);
	}

	itm=mobs.begin();
	while(itm!=mobs.end()){
		if((*itm)->is_ready()==true){
			set_direction(**itm);
			(*itm)->move();
			(*itm)->draw(win);
		}
		else{
			time=clock.getElapsedTime();
			timeInt=time.asSeconds();
			if(timeInt%2==1){
				(*itm)->start();
				clock.restart();
			}
		}
		++itm;
	}
	
	itm=mobs.begin();
	while(itm!=mobs.end()){
		if(int((*itm)->get_pos_x())==int(get_end_x())&&int((*itm)->get_pos_y())==int(get_end_y())){
			delete (*itm);
			mobs.erase(itm);
			console.subtract_life();
			break;
		}
		++itm;
	}
	itm=mobs.begin();
	while(itm!=mobs.end()){
		if((**itm).get_health()<=0){
			console.add_resources((*itm)->get_worth());
			delete *itm;
			mobs.erase(itm);
			break;
		}
		++itm;
	}
	if(chosen!=NULL)
		(*chosen).draw2(win);

	itt=towers.begin();
	while(itt!=towers.end()){
		(*itt)->draw(win);
		(*itt)->fire();
		itm=mobs.begin();
		while(itm!=mobs.end()){
			(*itt)->check_collisions(**itm);
			++itm;
		}
		++itt;
	}

}

double map::map::get_start_x()
{
	return start_x;
}


double map::map::get_start_y()
{
	return start_y;
}

double map::map::get_end_x()
{
	return end_x;
}

double map::map::get_end_y()
{
	return end_y;
}

void map::map::move_chosen_l()
{
	if(chosen!=NULL){
		int i=0;
		if(chosen!=track) //przsuwa raz zeby zastosowac warunek w petli
			chosen--;
		else
			chosen=&track[width*height-1];
		while((*chosen).get_type()!=1&&i!=height*width){
			if(chosen!=track)
				chosen--;
			else
				chosen=&track[width*height-1];
			i++;
		}
		if(i==width*height)
			chosen=NULL;
	}
}

void map::map::move_chosen_r()
{
	if(chosen!=NULL){
		int i=0;
		if(chosen!=&track[width*height-1])  //przesuwa raz zeby zastosowac warunek w petli
			chosen++;
		else
			chosen=track;
		while((*chosen).get_type()!=1&&i!=height*width){
			if(chosen!=&track[width*height-1])
				chosen++;
			else
				chosen=track;
			i++;
		}
		if(i==width*height)
			chosen=NULL;
	}
}

void map::map::set_direction(mob &m){//poruszanie mobem po torze
	int x=m.get_pos_x();
	int y=m.get_pos_y();
	int tmp=0;
	if(m.get_destination()!=1){
		for(int i=1;i<31;i++)
			if(track2[x-i][y]==1)
				tmp=2;	
	}
	if(m.get_destination()!=2){
		for(int i=1;i<31;i++)
			if(track2[x+i][y]==1)
				tmp=1;
	}
	if(m.get_destination()!=3){
		for(int i=1;i<31;i++)
			if(track2[x][y-i]==1)
				tmp=4;
	}
	if(m.get_destination()!=4){
		for(int i=1;i<31;i++)
			if(track2[x][y+i]==1)
				tmp=3;
	}
	m.set_destination(tmp);
}