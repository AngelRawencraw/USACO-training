{
PROG: beads
LANG: PASCAL
}
{��� - beads
����
������ñ�׼��������O(n^2)�ģ����������ƶ�̬�滮�ķ����Ż���O(n)��
������bl,br,rl,rr�ֱ��¼������i�����������ռ�����ɫ��ɫ��������
�����ǻ��εģ�������ֻҪ������ͬ������������һ�飬�Ͱ���ת�������Ե��ˡ�
����ֻҪ���bl,br,rl,rr����ô�������max(max(bl[i],rl[i])+max(br[i+1],rr[i+1])) (0<=i<=2*n-1)��
��������bl,rlΪ��:
��ʼʱbl[0]=rl[0]=0
���Ǵ������Ҽ���
���necklace[i]='r',rl[i]=rl[i-1]+1,bl[i]=0��
���necklace[i]='b', bl[i]=bl[i-1]+1,rl[i]=0��
���necklace[i]='w',bl[i]=bl[i-1]+1,rl[i]=rl[i-1]+1��
ͬ��������br,rr��
}
program beads;
type node=record
	ch:char;
	up,down:integer;
	end;
var 
	pos:array[1..10000]of node;
	n,total:longint;
procedure init;
var i,j:integer;
begin
    for i:=1 to n do
    begin
		read(pos[i].ch);
		if i=1 then pos[i].up:=n else pos[i].up:=i-1;
		if i=n then pos[i].down:=1 else pos[i].down:=i+1;
	end;
end;
procedure main;
var 
		i,tr,tb,k,temp,zq:integer;
begin
	total:=-1;
	 for i:=1 to n do
	 begin
         tr:=0;tb:=0;
		 k:=i;zq:=0;{���ڼ�¼���ڷ�ֹ����ѭ��}
		 while true do
	     begin
			 if zq>n-1 then break;
			 if (pos[k].ch='w') or (pos[k].ch='r') then inc(tr) else break;inc(zq);
				 
			k:=pos[k].down;
		 end;
		k:=i;
	     while true do
	     begin
			  if zq>n-1 then break;
			 if (pos[k].ch='w') or (pos[k].ch='b') then inc(tb) else break;inc(zq);
				
				 k:=pos[k].down;
		 end;
			 if tr>tb then temp:=tr else temp:=tb;
		tr:=0;tb:=0;
		k:=i-1;
		 while true do
	     begin
			  if zq>n-1 then break;
			 if (pos[k].ch='w') or (pos[k].ch='r') then inc(tr) else break;inc(zq);
				
			k:=pos[k].up;
		end;
		k:=i-1;
	     while true do
	     begin
			  if zq>n-1 then break;
			 if (pos[k].ch='w') or (pos[k].ch='b') then inc(tb) else break;inc(zq);
				
				 k:=pos[k].up;
		end;
			 if tr>tb then temp:=tr+temp else temp:=tb+temp;
			if temp>total then total:=temp;
		end;
end;
begin
  assign(input,'beads.in');
  reset(input);
  assign(output,'beads.out');
  rewrite(output);
  readln(n);
  init;
  main;
  writeln(total);
  close(input);
  close(output);
end.