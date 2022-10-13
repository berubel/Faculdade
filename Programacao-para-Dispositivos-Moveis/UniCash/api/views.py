from rest_framework.decorators import api_view
from rest_framework.response import Response
from api.models import Receipt, Users
from .serializers import ReceiptSerializer
from django.shortcuts import get_object_or_404
from rest_framework.status import HTTP_200_OK, HTTP_400_BAD_REQUEST

# Create your views here.

# Endpoint list
@api_view(['GET'])
def api_overview(request):
    api_urls = {
        'Wallet-List':'/wallet-list/',
        'Wallet-Detail':'/wallet-detail/<int:pk>/',
        'Wallet-Create':'/wallet-create/',
        'Transfer': '/transfer/<int:pk>/',
        'Receipt-list':'/receipt-list/',
        'Receipt-detail':'/receipt-detail/',
    }
    return Response(api_urls)

# # Endpoint to list all wallets
# @api_view(['GET'])
# def wallet_list(request):
#     wallet = Wallet.objects.all()
#     serializer = WalletSerializer(wallet, many=True)

#     return Response(serializer.data)

# # Endpoint to list a specific wallet
# @api_view(['GET'])
# def wallet_detail(request, pk):
#     wallet = get_object_or_404(Wallet, pk=pk)
#     serializer = WalletSerializer(wallet, many=False)

#     return Response(serializer.data)

# # Endpoint to create a wallet for a user
# @api_view(['POST'])
# def wallet_create(request, pk):
#     user = get_object_or_404(Users, pk=pk)

#     wallet =  Wallet (
#      user_id=user
#     )
#     wallet.save() 
#     serializer = WalletSerializer(wallet, many=False)

#     return Response(serializer.data)

# Endpoint to update a wallet balance and create a receipt after a transfer
# @api_view(['PUT', 'POST'])
# def transfer(request, pk):

#     transfer_user = request.data.get('transfer_user')
#     transfer_value = request.data.get('transfer_value')

#     user = get_object_or_404(Users, enrollment=transfer_user)
    
#     transfer_wallet = Wallet.objects.get(pk=user.id)
#     wallet = Wallet.objects.get(pk=pk)

#     if transfer_value > wallet.balance:
#        return Response({'sufficient_funds': False})
#     else:
#         wallet.balance = wallet.balance - transfer_value
#         transfer_wallet.balance = transfer_wallet.balance + transfer_value
#         wallet.save()
#         transfer_wallet.save()

#         wallet_id = pk
#         data = {'transfer_user':transfer_user, 
#                 'transfer_value':transfer_value, 
#                 'wallet_id':wallet_id}

#         serializer = ReceiptSerializer(data=data)

#         if serializer.is_valid():
#             serializer.save()
#             transfer_value=0
#             return Response(data=serializer.data, status=HTTP_200_OK)

#         return Response(data=serializer.errors, status=HTTP_400_BAD_REQUEST)
            
# # Endpoint to list all receipts
# @api_view(['GET'])
# def receipt_list(request):
#     receipt = Receipt.objects.all()
#     serializer = ReceiptSerializer(receipt, many=True)

#     return Response(serializer.data)

# # Endpoint to list a specefic receipt
# @api_view(['GET'])
# def receipt_detail(request, pk):
#     receipt = get_object_or_404(Receipt, pk=pk)
#     serializer = ReceiptSerializer(receipt, many=False)

#     return Response(serializer.data)