#ifndef _IMAGE_H_
#define _IMAGE_H_

class Image{
    public:
    int getHeight( ) const;
    int getWidth( ) const;
    

    private:
    Image( );
    Image( const int& height, const int& width );
    bool indexValid( const int& row, const int& column, const int& channel ) const;
    int index( const int& row, const int& column, const int& channel ) const; 
    int getChannel( const int& row, const int& column, const int& channel ) const;
    void setHeight( const int& height );
    void setWidth( const int& width );
    void setChannel( const int& row, const int& column, const int& channel, const int& value );
    
}

#endif /*IMAGE_H_ 
Local Variables:
mode:c++
End: */