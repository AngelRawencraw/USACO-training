Var
  c:char;
  fit,seq:string;
  i,j,l,p,lp:longint;
  ans:array[0..200000]of longint;
  primitives:array[1..200]of string;
Function exist(si:string):boolean;
  Begin
    For j:=1 to lp do If primitives[j]=si then exit(true);
    exit(false)
  End;
Begin
  assign(input,'prefix.in');  reset(input);
  assign(output,'prefix.out');  rewrite(output);
  seq:='           ';  //���ַ���ģ����� ��Ϊ�primitiveֻ��10λ ����ֻ��¼11λ
  fit:='00000000001';  //��Ӧ����ÿһλ ��¼��λ��(1)��(0)Ϊһ��ǰ׺��ĩβ
  ans[0]:=0;  lp:=1;   //ans[n]Ϊ�Ե�nΪ��β�� �ǰ׺�ĳ���
  Repeat               //����primitives
    read(c);
    Case c of
      ' ':inc(lp);
      'A'..'Z':primitives[lp]:=primitives[lp]+c
    End;
    If eoln then      //�н���
      Begin
        readln;  inc(lp)
      End
  Until c='.';
  Repeat
    read(c);
    If eoln then readln;
    seq:=copy(seq,2,10)+c;  //����
     fit:=copy(fit,2,10)+'0';
    inc(l);  ans[l]:=ans[l-1];
    For p:=10 downto 1 do
      If (fit[p]='1')and(exist(copy(seq,p+1,11-p))) then //���ҿ��Գ�֮Ϊdp
        Begin
          fit:=copy(fit,1,10)+'1';
          ans[l]:=ans[l+p-11]+11-p;
          break
        End;
  Until (eof)or(fit='00000000000');//�������11����������Ҫ�� ����ǰ׺����
  writeln(ans[l]);
  close(input);  close(output)
End.
