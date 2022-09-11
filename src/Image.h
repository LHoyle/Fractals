#ifndef _IMAGE_H_
#define _IMAGE_H_

class Image{
    public:
    int getHeight( ) const{
        return self.height
    }
    int getWidth( ) const{
        return self.width
    }
    int getChannel( const int& row, const int& column, const int& channel ) const;
    void setHeight( const int& height ){
        self.height=height
        return
    }
    void setWidth( const int& width ){
        self.width=width
        return
    }
    void setChannel( const int& row, const int& column, const int& channel, const int& value );
    

    private:
    Image( );
    Image( const int& height, const int& width );
    bool indexValid( const int& row, const int& column, const int& channel ) const;
    int index( const int& row, const int& column, const int& channel ) const; 
}

#endif /*IMAGE_H_ 
Local Variables:
mode:c++
End: */