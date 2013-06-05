#include "map.h"
#include <fstream>
#include <string>
#include "mob1.h"
#include "tower1.h"
#include "tower2.h"

map::map::map(void)
{
	
	load_level("lvl.txt");
	for(int i=0;;i++)
		if(track[i].get_type()==1){
			chosen=&track[i];
			break;
		}
}


map::map::~map(void)
{
}

void map::map::begin_wave(double px, double py, std::string s, double vel, double hlth, int wrth, int hm)
{
	itm=mobs.begin();
	//mob *wsk=new mob(px, py, s, vel, hlth, wrth, 0);
	//mobs.insert(itm, hm, wsk);
	//while(hm--)
	mobs.push_back(new mob(px, py, s, vel, hlth, wrth, 0));

	//int x=0;
	//for(int i=0;i<hm;i++){
	//	(*itm)->move(x, 0);
	//	++itm;
	//	x+=30;
	//}
	/*while(hm--){
		itm=mobs.begin();
		mob *wsk=new mob(px, py, s, vel, hlth, wrth);
		mobs_list.insert(itm, *wsk);
	}*/
	/*while(itm!=mobs.end()){
		(*itm)->move();
		++itm;
		x+=30;
	}*/
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
					tile *wsk=new tile(x,y,"tor1.bmp",1);
					track[tiles]=*wsk;
					tiles++;
					break;
					}
				case 'X':
					{
					tile *wsk=new tile(x,y,"tor2.bmp",2);
					track[tiles]=*wsk;
					tiles++;
					track2[x][y]=1;
					break;
					}
				case 'S'://pierwszy tile trasy po ktorej ida moby
					{
					tile *wsk=new tile(x,y,"tor2.bmp", 3);
					track[tiles]=*wsk;
					tiles++;
					track2[x][y]=1;
					break;
					}
				case 'E'://ostatni tile trasy po ktorej ida moby
					{
					tile *wsk=new tile(x,y,"tor2.bmp", 4);
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
	tower *wsk;
	switch ( which_tower ) {
	case 1:
		wsk=new tower1((*chosen).get_pos_x(), (*chosen).get_pos_y(), s, spd, cst);
		break;
	case 2:
		wsk=new tower2((*chosen).get_pos_x(), (*chosen).get_pos_y(), s, spd, cst, 0.1);
		break;
	}
	towers.push_back(wsk);
	(*chosen).set_type(0);
	move_chosen_r();
	console.subtract_resources(cst);
}

void map::map::display(sf::RenderWindow &win, engine::player_console &console){

	/*for(int i=0;i<width;i++)
		for(int j=0;j<height;j++)
			track[i][j].draw(win);*/
	for(int i=0;i<width*height;i++)
		track[i].draw(win);
	

	itm=mobs.begin();
	/*if(itm!=mobs.end()&&(*itm)->get_pos_x()==get_end_x()&&(*itm)->get_pos_y()==get_end_y()){
		int tmp=mobs.size();
		while(tmp--)
			console.subtract_life();
		mobs.clear();
		itm=mobs.begin();
	}*/
	while(itm!=mobs.end()){
		
		set_direction(*(*itm));
		(*itm)->move();
		(*itm)->draw(win);
		++itm;
	}

	if(chosen!=NULL)
		(*chosen).draw2(win);

	itt=towers.begin();
	while(itt!=towers.end()){
		(*itt)->draw(win);
		(*itt)->fire();
		++itt;
	}
}

double map::map::get_start_x()
{
	for(int i=0;;i++)
		if(track[i].get_type()==3){
			return track[i].get_pos_x();
			break;
		}
}

double map::map::get_start_y()
{
	for(int i=0;;i++)
		if(track[i].get_type()==3){
			return track[i].get_pos_y();
			break;
		}
}

double map::map::get_end_x()
{
	for(int i=0;;i++)
		if(track[i].get_type()==4){
			return track[i].get_pos_x();
			break;
		}
}

double map::map::get_end_y()
{
	for(int i=0;;i++)
		if(track[i].get_type()==4){
			return track[i].get_pos_y();
			break;
		}

}

void map::map::move_chosen_l()
{
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

void map::map::move_chosen_r()
{
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