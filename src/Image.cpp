#include "Image.h"

Image::Image()
{
    mHeight = 0;
    mWidth = 0;
}
Image::Image(const int &height, const int &width)
{
    mHeight = height;
    mWidth = width;
    pixelvector.resize(mHeight * mWidth * 3);
}
int Image::getHeight() const
{
    return mHeight;
}
int Image::getWidth() const
{
    return mWidth;
}
int Image::getChannel(const int &row, const int &column, const int &channel) const
{
    if (indexValid (row, column, channel))
    {
        return pixelvector[index(row, column, channel)];
    }
    else
    {
        return -1;
    }
}
void Image::setHeight(const int &height)
{
    if (height>=0){
    mHeight = height;
    pixelvector.resize(3*mHeight*mWidth);
    return;
    }
}
void Image::setWidth(const int &width)
{
    if (width >=0){
    mWidth = width;
    pixelvector.resize(3*mHeight*mWidth);
    return;
    }
}
void Image::setChannel(const int &row, const int &column, const int &channel, const int &value)
{
    if (indexValid (row, column, channel))
    {
        pixelvector[index(row, column, channel)] = value;
    }
}
bool Image::indexValid(const int &row, const int &column, const int &channel) const
{
    if (row >= mHeight || row < 0)
    {
        return false;
    }
    else if (column >= mWidth || column < 0)
    {
        return false;
    }
    else if (channel > 2 || channel < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int Image::index(const int &row, const int &column, const int &channel) const
{
    return (row * mWidth * 3 + column * 3) + channel;
}