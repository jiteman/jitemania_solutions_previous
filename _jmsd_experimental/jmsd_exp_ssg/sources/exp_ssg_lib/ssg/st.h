#pragma once


// #include "jmsf/types.h"


template<class ele>
struct el
{
  ele v;
  el*next;
};

template< class ele >
void delel( el< ele > *el1 ) {
  if ( el1->next != nullptr ) {
	  delel( el1->next );
  }

  delete el1;
}

/////////////////////////////
template<class T>
void DoForEach(el<T>*beg,void(*act)(T*))
{
	el<T>* tmp=beg;
	while(tmp)
	{
		act(&tmp->v);
		tmp=tmp->next;
	}
}
template<class T>
void DoForEach(T*beg,void(*act)(T*),int num)
{

	while(num)
	{
		num--;
		act(beg);
		beg++;

	}
}

template<class ele>
class st
{
public:
	el<ele>*beg;

	st(){beg=0;}
	bool AddEl(ele);
	void DelEl(el<ele>*prv);
	void DelEl(ele vl);
	bool Delete(ele v);

	void renull();
	bool Exists(ele v);
	void AddEltoBeg(ele);
void AddStDBL(el<ele>*s);
  ~st(){renull();}

  int GetNum(){el<ele>*tmp=beg;int res=0;while(tmp){tmp=tmp->next;res++;}return res;}
  el<ele>* GetLast(){el<ele>*tmp=beg;if(!tmp)return 0;while(tmp->next){tmp=tmp->next;}return tmp;}
  ele* GetById(int id)
  {
	  el<ele>*tmp=beg;
	  while(tmp)
	  {
		  if(!id)return &tmp->v;
		  tmp=tmp->next;
		  id--;
	  }
	  return 0;
  }
};
template<class ele>
void st<ele>::DelEl(el<ele>*prv)
{
	el<ele>*tmp;
	if(beg==0)return;
	if(prv==0)
	{
		tmp=beg->next;
		delete beg;
		beg=tmp;
	}else
	{
		tmp=prv->next->next;
		delete prv->next;
		prv->next=tmp;
	}


}

template<class ele>
bool st<ele>::Exists(ele v)
{
   el<ele>*tmp=beg;
   while(tmp!=nullptr){if(tmp->v==v)return 1;tmp=tmp->next;}
   return 0;
}

template<class ele>
bool st<ele>::Delete(ele v)
{
   el<ele>*tmp=beg,*tmp2=0;
   while(tmp!=nullptr)
   {
	   if(tmp->v==v)
	   {

		   tmp=tmp->next;
		   if(tmp2)
		   {
		      delete tmp2->next;
			  tmp2->next=tmp;
		   }
		   else
		   {
			   delete beg;
			   beg=tmp;
		   }


		   return 1;
	   }
	   tmp2=tmp;
	   tmp=tmp->next;
   }
   return 0;
}
template<class ele>
void st<ele>::AddEltoBeg(ele vl)
{
	el<ele>*tmp=beg;
	beg=new el<ele>;
	beg->next=tmp;
	beg->v=vl;
}
template<class ele>
bool st<ele>::AddEl(ele vl)
{
  if(beg==nullptr)
  {
    beg=new el<ele>;
    beg->next=nullptr;
    beg->v=vl;
    return 1;
  }
  el<ele>*tmp=beg;
  while(tmp->next){if(tmp->v==vl)return 0;tmp=tmp->next;}
  if(tmp->v==vl)return 0;
  tmp->next=new el<ele>;
  tmp->next->v=vl;
  tmp->next->next=nullptr;
  return 1;
}

template<class ele>
void st<ele>::DelEl(ele vl)
{
  el<ele>*tmp=beg,*tmp2;
  if(!beg)return;

  if(beg->v==vl)
  {
	  tmp2=beg->next;
	  delete beg;

	  beg=tmp2;
	  return;
  }

  if(!tmp->next)return;

  while(tmp->next->next)
  {
	  if(tmp->next->v==vl)
	  {
		  tmp2=tmp->next->next;
		  delete (tmp->next);
		  tmp->next=tmp2;
		  return;
	  }
	  tmp=tmp->next;
  }

  if(tmp->next->v==vl)
  {
	  delete (tmp->next);
	  tmp->next=0;
  }

}

template<class ele>
void st<ele>::renull()
{
  if(beg)delel(beg);
  beg=0;
}

template<class ele>
class st_iterator
{
	st<ele>* ss;
	el<ele>*i,*i1;
public:
	st_iterator(){i=0;}
	void AcceptSt(st<ele>*s)
	{
		i=s->beg;
		i1=0;
		ss=s;
	}
	st_iterator(st<ele>*s)
	{
		AcceptSt(s);
	}
	void Next()
	{
		if(!i)return;
		i1=i;
		i=i->next;
	}
	ele* GetCurrent(){return &i->v;}
	bool IsDone(){return (i==0);}
	void DeleteCur()
	{

		if(!i)return;
		i=i->next;

		if(!i1)
		{

			delete ss->beg;
			ss->beg=i;

		}else
		{

			delete i1->next;
			i1->next=i;

		}

	}
};

template<class ele>
void st<ele>::AddStDBL(el<ele>*p_beg)
{
	while(p_beg)
	{
		AddEltoBeg(p_beg->v);
		p_beg=p_beg->next;
	}
}

template<class ele>
void CopyElements(el<ele>**to,el<ele>*from)
{
	el<ele>* tmp;
	while(from)
	{
		tmp=new el<ele>;
		tmp->v=from->v;
		tmp->next=*to;
		*to=tmp;
		from=from->next;
	}
}
/////////////////////////////

/*
template<class ele>
class st2
{public:
  el<ele>*beg;

  int n;

  st2(){n=0;beg=NULL;}
  BOOL AddEl(ele);
  void AddElDBL(ele);
  void AddStDBL(st2<ele>*);
  void renull();
  void DelEl(ele);
  BOOL Exists(ele v);
	void AddStDBL(el<ele>*bg);
  ~st2(){renull();}
};

template<class ele>
class st2_iterator
{
	st2<ele>* ss;
	el<ele>*i,*i1;
public:
	st2_iterator(){i=0;}
	st2_iterator(st2<ele>*s)
	{
		i=s->beg;
		i1=0;
		ss=s;
	}
	void Next()
	{
		if(!i)return;
		i1=i;
		i=i->next;
	}
	ele* GetCurrent(){return &i->v;}
	bool IsDone(){return (i==0);}
	void DeleteCur()
	{

		if(!i)return;
		i=i->next;

		if(!i1)
		{

			delete ss->beg;
			ss->beg=i;

		}else
		{

			delete i1->next;
			i1->next=i;

		}
		ss->n--;

	}
};

template<class ele>
BOOL st2<ele>::Exists(ele v)
{
   el<ele>*tmp=beg;
   while(tmp!=NULL){if(tmp->v==v)return 1;tmp=tmp->next;}
   return 0;
}
template<class ele>
BOOL st2<ele>::AddEl(ele vl)
{
  if(beg==NULL)
  {
    beg=new el<ele>;
    beg->next=NULL;
    beg->v=vl;
	n=1;
    return 1;
  }
  el<ele>*tmp=beg;
  while(tmp->next!=NULL){if(tmp->v==vl)return 0;tmp=tmp->next;}
  if(tmp->v==vl)return 0;
  n++;
  tmp->next=new el<ele>;
  tmp->next->v=vl;
  tmp->next->next=NULL;
  return 1;
}

template<class ele>
void st2<ele>::AddStDBL(st2<ele>*s)
{
	el<ele>*tmp=beg;
	if(!tmp)
	{
		beg=s->beg;
		n=s->n;
	}else
	{
	    while(tmp->next)	tmp=tmp->next;
	    tmp->next=s->beg;
	    n+=s->n;
	}
	s->n=0;
	s->beg=NULL;


}
template<class ele>
void st2<ele>::AddStDBL(el<ele>*bg)
{
	while(bg)
	{
		AddElDBL(bg->v);
		bg=bg->next;
	}


}
template<class ele>
void st2<ele>::AddElDBL(ele vl)
{
  if(beg==NULL)
  {
    beg=new el<ele>;
    beg->next=NULL;
    beg->v=vl;
	n=1;
    return;
  }
  el<ele>*tmp=beg;
  while(tmp->next!=NULL){tmp=tmp->next;}
  n++;
  tmp->next=new el<ele>;
  tmp->next->v=vl;
  tmp->next->next=NULL;

}

template<class ele>
void st2<ele>::DelEl(ele vl)
{
  el<ele>*tmp=beg,*tmp2;
  if(!n)return;
  if(n==1 && beg->v==vl)
  {

	  delete beg;
	  beg=NULL;
	  n=0;
	  return;
  }

  if(beg->v==vl)
  {
	  tmp2=beg->next;
	  delete beg;

	  beg=tmp2;
	  n--;
	  return;
  }


  while(tmp->next->next!=NULL)
  {
	  if(tmp->next->v==vl)
	  {
		  tmp2=tmp->next->next;
		  delete (tmp->next);
		  tmp->next=tmp2;
		  n--;
		  return;
	  }
	  tmp=tmp->next;
  }

  if(tmp->next->v==vl)
  {
	  delete (tmp->next);
	  tmp->next=NULL;
	  n--;
  }

}


template<class ele>
void st2<ele>::renull()
{
  if(n)delel(beg);
  beg=NULL;
  n=0;
}
*/


template<class ele>
class stek
{public:
  el<ele>*top,*beg;



  stek(){top=nullptr;beg=nullptr;}
  void AddEl(ele);
  void AddElToBeg(ele);
  int GetNum(){el<ele>*tmp=top;int res=0;while(tmp){tmp=tmp->next;res++;}return res;}

  void DeleteEl();

  void renull();



  ele GetElem()  {	return top->v;  }

  ~stek(){renull();}
};

template<class ele>
void stek<ele>::DeleteEl()
{
	if(!top)return;
	if(!top->next)
	{

		delete top;
		top=nullptr;
		beg=nullptr;

		return;
	}
	el<ele>*tmp=top;

	top=top->next;
	delete tmp;
}

template<class ele>
void stek<ele>::AddEl(ele vl)
{
  if(!top)
  {
    top=new el<ele>;

    top->next = nullptr;
    top->v=vl;
	beg=top;
    return;
  }
  el<ele>*tmp=new el<ele>;
  tmp->next=top;
  top=tmp;
  top->v=vl;
  return;
}

template<class ele>
void stek<ele>::AddElToBeg(ele vl)
{
  if(!top)
  {
    top=new el<ele>;
	beg=top;
    top->next = nullptr;
    top->v=vl;
    return;
  }
  beg->next=new el<ele>;
  beg=beg->next;
  beg->next = nullptr;
  beg->v=vl;
  return;
}

template<class ele>
void stek<ele>::renull()
{
  if(top)delel(top);

  beg=nullptr;
  top=nullptr;
  return;
}
