clear;clc;close all;
src=im2double(imread('clockA.bmp'));
dst=im2double(imread('clockB.bmp'));

[Cs,Ss]=wavedec2(src,3,'db1');
[Cd,Sd]=wavedec2(dst,3,'db1');
fun=@(x) sum(x(:))/numel(x);

[cA3s,cH3s,cV3s,cD3s,cH2s,cV2s,cD2s,cH1s,cV1s,cD1s]=wave2mat(Cs,Ss);
Ms=[[[cA3s,cH3s;cV3s,cD3s],cH2s;cV2s,cD2s],cH1s;cV1s,cD1s];

[cA3d,cH3d,cV3d,cD3d,cH2d,cV2d,cD2d,cH1d,cV1d,cD1d]=wave2mat(Cd,Sd);
Md=[[[cA3d,cH3d;cV3d,cD3d],cH2d;cV2d,cD2d],cH1d;cV1d,cD1d];
alpha=0.5;

cA3=(cA3d+cA3s)/2;

Es=cH3s.*cH3s;Es=nlfilter(Es,[3,3],fun);
Ed=cH3d.*cH3d;Ed=nlfilter(Ed,[3,3],fun);
M=cH3s.*cH3d;M=nlfilter(M,[3,3],fun);M=2*M;
M=M./(Es+Ed);
cH3=zeros(32,32);
for i=1:32
    for j=1:32
      if(M(i,j)>=0.5)
          cH3(i,j)=max(cH3s(i,j),cH3d(i,j));
      else
          wmin=0.5-0.5*(1-M(i,j)/(1-alpha));
          wmax=1-wmin;
          cH3(i,j)= wmax*(max(cH3s(i,j),cH3d(i,j)))+wmin*(min(cH3s(i,j),cH3d(i,j)));
      end
    end
end

Es=cV3s.*cV3s;Es=nlfilter(Es,[3,3],fun);
Ed=cV3d.*cV3d;Ed=nlfilter(Ed,[3,3],fun);
M=cV3s.*cV3d;M=nlfilter(M,[3,3],fun);M=2*M;
M=M./(Es+Ed);
cV3=zeros(32,32);
for i=1:32
    for j=1:32
      if(M(i,j)>=0.5)
          cV3(i,j)=max(cV3s(i,j),cV3d(i,j));
      else
          wmin=0.5-0.5*(1-M(i,j)/(1-alpha));
          wmax=1-wmin;
          cV3(i,j)= wmax*(max(cV3s(i,j),cV3d(i,j)))+wmin*(min(cV3s(i,j),cV3d(i,j)));
      end
    end
end

Es=cD3s.*cD3s;Es=nlfilter(Es,[3,3],fun);
Ed=cD3d.*cD3d;Ed=nlfilter(Ed,[3,3],fun);
M=cD3s.*cD3d;M=nlfilter(M,[3,3],fun);M=2*M;
M=M./(Es+Ed);
cD3=zeros(32,32);
for i=1:32
    for j=1:32
      if(M(i,j)>=0.5)
          cD3(i,j)=max(cD3s(i,j),cD3d(i,j));
      else
          wmin=0.5-0.5*(1-M(i,j)/(1-alpha));
          wmax=1-wmin;
          cD3(i,j)= wmax*(max(cD3s(i,j),cD3d(i,j)))+wmin*(min(cD3s(i,j),cD3d(i,j)));
      end
    end
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%
Es=cH2s.*cH2s;Es=nlfilter(Es,[3,3],fun);
Ed=cH2d.*cH2d;Ed=nlfilter(Ed,[3,3],fun);
M=cH2s.*cH2d;M=nlfilter(M,[3,3],fun);M=2*M;
M=M./(Es+Ed);
cH2=zeros(64,64);
for i=1:64
    for j=1:64
      if(M(i,j)>=0.5)
          cH2(i,j)=max(cH2s(i,j),cH2d(i,j));
      else
          wmin=0.5-0.5*(1-M(i,j)/(1-alpha));
          wmax=1-wmin;
          cH2(i,j)= wmax*(max(cH2s(i,j),cH2d(i,j)))+wmin*(min(cH2s(i,j),cH2d(i,j)));
      end
    end
end


Es=cV2s.*cV2s;Es=nlfilter(Es,[3,3],fun);
Ed=cV2d.*cV2d;Ed=nlfilter(Ed,[3,3],fun);
M=cV2s.*cV2d;M=nlfilter(M,[3,3],fun);M=2*M;
M=M./(Es+Ed);
cV2=zeros(64,64);
for i=1:64
    for j=1:64
      if(M(i,j)>=0.5)
          cV2(i,j)=max(cV2s(i,j),cV2d(i,j));
      else
          wmin=0.5-0.5*(1-M(i,j)/(1-alpha));
          wmax=1-wmin;
          cV2(i,j)= wmax*(max(cV2s(i,j),cV2d(i,j)))+wmin*(min(cV2s(i,j),cV2d(i,j)));
      end
    end
end

Es=cD2s.*cD2s;Es=nlfilter(Es,[3,3],fun);
Ed=cD2d.*cD2d;Ed=nlfilter(Ed,[3,3],fun);
M=cD2s.*cD2d;M=nlfilter(M,[3,3],fun);M=2*M;
M=M./(Es+Ed);
cD2=zeros(64,64);
for i=1:64
    for j=1:64
      if(M(i,j)>=0.5)
          cD2(i,j)=max(cD2s(i,j),cD2d(i,j));
      else
          wmin=0.5-0.5*(1-M(i,j)/(1-alpha));
          wmax=1-wmin;
          cD2(i,j)= wmax*(max(cD2s(i,j),cD2d(i,j)))+wmin*(min(cD2s(i,j),cD2d(i,j)));
      end
    end
end
%%%%%%%%%%%%
Es=cH1s.*cH1s;Es=nlfilter(Es,[3,3],fun);
Ed=cH1d.*cH1d;Ed=nlfilter(Ed,[3,3],fun);
M=cH1s.*cH1d;M=nlfilter(M,[3,3],fun);M=2*M;
M=M./(Es+Ed);
cH1=zeros(128,128);
for i=1:128
    for j=1:128
      if(M(i,j)>=0.5)
          cH1(i,j)=max(cH1s(i,j),cH1d(i,j));
      else
          wmin=0.5-0.5*(1-M(i,j)/(1-alpha));
          wmax=1-wmin;
          cH1(i,j)= wmax*(max(cH1s(i,j),cH1d(i,j)))+wmin*(min(cH1s(i,j),cH1d(i,j)));
      end
    end
end


Es=cV1s.*cV1s;Es=nlfilter(Es,[3,3],fun);
Ed=cV1d.*cV1d;Ed=nlfilter(Ed,[3,3],fun);
M=cV1s.*cV1d;M=nlfilter(M,[3,3],fun);M=2*M;
M=M./(Es+Ed);
cV1=zeros(128,128);
for i=1:128
    for j=1:128
      if(M(i,j)>=0.5)
          cV1(i,j)=max(cV1s(i,j),cV1d(i,j));
      else
          wmin=0.5-0.5*(1-M(i,j)/(1-alpha));
          wmax=1-wmin;
          cV1(i,j)= wmax*(max(cV1s(i,j),cV1d(i,j)))+wmin*(min(cV1s(i,j),cV1d(i,j)));
      end
    end
end

Es=cD1s.*cD1s;Es=nlfilter(Es,[3,3],fun);
Ed=cD1d.*cD1d;Ed=nlfilter(Ed,[3,3],fun);
M=cD1s.*cD1d;M=nlfilter(M,[3,3],fun);M=2*M;
M=M./(Es+Ed);
cD1=zeros(128,128);
for i=1:128
    for j=1:128
      if(M(i,j)>=0.5)
          cD1(i,j)=max(cD1s(i,j),cD1d(i,j));
      else
          wmin=0.5-0.5*(1-M(i,j)/(1-alpha));
          wmax=1-wmin;
          cD1(i,j)= wmax*(max(cD1s(i,j),cD1d(i,j)))+wmin*(min(cD1s(i,j),cD1d(i,j)));
      end
    end
end
imshow(cD1,[]);
C=[reshape(cA3,[1,32*32]),reshape(cH3,[1,32*32]),reshape(cV3,[1,32*32]),reshape(cD3,[1,32*32]) ...
    reshape(cH2,[1,64*64]),reshape(cV2,[1,64*64]),reshape(cD2,[1,64*64]) ...
    reshape(cH1,[1,128*128]),reshape(cV1,[1,128*128]),reshape(cD1,[1,128*128])];

result=waverec2(C,Ss,'db1');
imshow(result,[]);
imwrite(result,'clock.jpg');


% Ed=Md.*Md;Ed=nlfilter(Ed,[3,3],fun);
% Es=Ms.*Ms;Es=nlfilter(Es,[3,3],fun);
% 
% 
% M=Md.*Ms;
% M=nlfilter(M,[3,3],fun);
% M=2*M;
% div=Ed+Es;
% M=M./div;
% [Y,~] = mapminmax(M,0,1);
% threshold=0.2;
% R=zeros(256,256);
% for i=1:256
%     for j=1:256
%         if(M(i,j)<threshold)
%             R(i,j)=max(Ms(i,j),Md(i,j));
%         else
%             Wmin=0.5-0.5*(1-M(i,j)/(1-threshold));
%             Wmax=1-Wmin;
%             R(i,j)=Wmax*max(Ms(i,j),Md(i,j))+Wmin*min(Ms(i,j),Md(i,j));
%         end
%     end
% end
% tmp=Cd-Cs;tmp(tmp<=0)=0;tmp(tmp>0)=1;
% dmask=tmp;smask=1-dmask;
% Cs=Cs.*smask;Cd=Cd.*dmask;
% C=Cs+Cd;
% 
% rows=Ss(1,1);
% cols=Ss(1,2);
% LL3s=Cs(1:rows*cols);
% LL3d=Cd(1:rows*cols);
% 
% 
% LL3=(LL3s+LL3d)/2;
% C(1:rows*cols)=LL3;
% t=reshape(C(1:rows*cols),[rows,cols]);
% R(1:rows,1:cols)=t;
% 
% 
% result=waverec2(C,Ss,'db3');
% figure,imshow(result,[]);
% imwrite(result,'result.jpg');
% 
% 
% 
