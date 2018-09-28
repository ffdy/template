struct point
{
	int elem;
	bool operator==(const point b) const
	{
		return this->elem == b.elem;
	}
	bool operator!=(const point b) const
	{
		return this->elem != b.elem;
	}
	bool operator<=(const point b) const
	{
		return this->elem <= b.elem;
	}
	bool operator<(const point b) const
	{
		return this->elem < b.elem;
	}
	bool operator>=(const point b) const
	{
		return this->elem >= b.elem;
	}
	bool operator>(const point b) const
	{
		return this->elem > b.elem;
	}
}a[10002],now;

