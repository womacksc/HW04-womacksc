#include "womackscStarbucks.h"

womackscStarbucks::womackscStarbucks(string data){
		readInFile(data);
}

void womackscStarbucks::readInFile(string data){
	ifstream fileIn;	
	istringstream strStream;	
	string str;		
	double x, y;	
	string name;

	fileIn.open(data, ifstream::in);
	fileIn.seekg(0, ifstream::beg);

	num_items_ = 500;
	location_ = new Entry[num_items_];

	while(!fileIn.eof()){
		for( int i=0; i<num_items_+1; i++){
			if(i == num_items_){
				// change size of Entry[]
				num_items_ = num_items_*2;
				Entry* temp = new Entry[num_items_];
				std::copy(temp, temp + num_items_, location_); 
				delete [] location_;
				location_ = temp;
			}
			getline(fileIn,str,'\r');
			strStream.str(str);

			getline(fileIn,str,',');
			strStream.str(str);
			location_[i].identifier = str;

			getline(fileIn,str,',');
			strStream.str(str);
			location_[i].x = lexical_cast<double>(str);

			getline(fileIn,str,',');
			strStream.str(str);
			location_[i].y = lexical_cast<double>(str);
		}
	}
}

/*void shuffleElements(Entry c, int size)
{
   int temporary;
   int randomNum;
   int last;

   for (last = size; last > 1; last--)
   {
      randomNum = rand() % last;
      temporary = c[randomNum];
      c[randomNum] = c[last - 1];
      c[last - 1] = temporary;
   }
}*/


Node* insert (Entry e, Node* r, bool xLevel){

	if(r==NULL) return new Node(r);
	if(abs(e.x - r->data_->x)<=0.00001 && abs(e.y - r->data_->y)<=0.00001) return r;
	if(xLevel){
		if(e.x < r->data_->x){
			r->left_ = insert(e, r->left_, !xLevel);
		}else{
			r->right_ = insert(e, r->right_, !xLevel);
		}
	}else{
		if(e.y < r->data_->y){
			r->left_ = insert(e, r->left_, !xLevel);
		}else{
			r->right_ = insert(e, r->right_, !xLevel);
		}
	}
	return r;
}

/*
	 * add all entries in the array to your data structure
	 *
	 * The "c" parameter is a pointer to an array of all the entries to be added, and n is the length of
	 * the array.
	 *
	 * Note: If you detect that two items have the same coordinates, then do not add the new item
	 *       that has the same coordinates as another item. This is guaranteed to happen, by the way,
	 *       because some Starbucks locations are listed in the database twice. We will define two locations
	 *       to be the "same location" if both |x1 - x2| <= 0.00001 and |y1 - y2| < 0.00001
	 */
	void womackscStarbucks::build(Entry* c, int n){
		insert (*c, root->left_, true);
	}

	Entry* search(double x, double y, Node* r, bool xLevel){
		
		double distanceX, distanceY; 
		double candidate;
		double nextCandidate;
		Entry* closest;


		if(xLevel){
		if(x < r->data_->x){
			r->left_->data_ = search(x, y, r->left_, !xLevel);
		}else{
			r->right_->data_ = search(x, y, r->right_, !xLevel);
		}
	}else{
		if(y < r->data_->y){
			r->left_->data_ = search(x, y, r->left_, !xLevel);
		}else{
			r->right_->data_ = search(x, y, r->right_, !xLevel);
		}	
			distanceX = r->data_->x-x;		
			distanceY = r->data_->y-y;		
			nextCandidate = sqrt(distanceX*distanceX + distanceY*distanceY);		
			if(nextCandidate<candidate){			
				closest = r->data_;			
				candidate = nextCandidate;			
			}	
		return closest;
	}
	}
	
	/*
	 * Return a pointer to the entry that is closest to the given coordinates. Your
	 *  answer may be approximate, but then you will lose points on the "Accuracy" quality measure
	 */
	Entry* womackscStarbucks::getNearest(double x, double y){
		return search(x, y, root, true);
	}


string womackscStarbucks::printLocationChange(double x, double y){
}

