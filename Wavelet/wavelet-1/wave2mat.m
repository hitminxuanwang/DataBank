function [cA3,cH3,cV3,cD3,cH2,cV2,cD2,cH1,cV1,cD1]=wave2mat(C,S)
    i=1;j=prod((S(1,:)));
    cA3=reshape(C(i:j),S(1,:));
    
    i=j+1;j=i+prod(S(2,:))-1;
    cH3=reshape(C(i:j),S(2,:));
    
    i=j+1;j=i+prod(S(2,:))-1;
    cV3=reshape(C(i:j),S(2,:));
    
    i=j+1;j=i+prod(S(2,:))-1;
    cD3=reshape(C(i:j),S(2,:));
    
    i=j+1;j=i+prod(S(3,:))-1;
    cH2=reshape(C(i:j),S(3,:));
    
    i=j+1;j=i+prod(S(3,:))-1;
    cV2=reshape(C(i:j),S(3,:));
    
    i=j+1;j=i+prod(S(3,:))-1;
    cD2=reshape(C(i:j),S(3,:));
    
    i=j+1;j=i+prod(S(4,:))-1;
    cH1=reshape(C(i:j),S(4,:));
    
    i=j+1;j=i+prod(S(4,:))-1;
    cV1=reshape(C(i:j),S(4,:));
    
    i=j+1;j=i+prod(S(4,:))-1;
    cD1=reshape(C(i:j),S(4,:));
    
    
    
    
    