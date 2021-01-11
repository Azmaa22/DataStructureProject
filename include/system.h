Queue<client> assignCasherToClient(client arr1[],casher arr2[],int len1,int len2){
    Queue<client> clientWaitting;
    int remainClient;

    remainClient=0;

    for(int i=0;i<len2;i++){
        if(arr2[i].getSrvingFlag()==0)
            {
               arr2[i].setServingFlag(1);
               arr1[i].setNumberOfCasher(i);
               ++remainClient;
            }
            }

   for(int i=remainClient;i<len1;i++){

    clientWaitting.Enqueu(arr1[i]);
   }

return clientWaitting;
}
