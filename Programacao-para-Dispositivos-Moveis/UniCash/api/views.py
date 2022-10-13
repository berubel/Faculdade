from rest_framework.decorators import api_view
from rest_framework.views import APIView
from rest_framework.response import Response
from api.models import Receipt, Users
from .serializers import ReceiptSerializer, TransferDataSerializer
from django.shortcuts import get_object_or_404
from rest_framework.status import (
    HTTP_200_OK, 
    HTTP_400_BAD_REQUEST, 
    HTTP_201_CREATED
    )

# Create your views here.

# Endpoint list
@api_view(['GET'])
def api_overview(request):
    api_urls = {
        'Transfer': '/transfer/<int:pk>/',
        'Receipt-list':'/receipt-list/',
        'Receipt-detail':'/receipt-detail/',
    }
    return Response(api_urls)

# Endpoint to send data to perform transfer and create a receipt
class TransferAPIView(APIView):
    def post(self, request, pk, format=None):
        user = get_object_or_404(Users, pk=pk)
        serializer = TransferDataSerializer(data=request.data)
      
        if serializer.is_valid():
            transfer_value = serializer.validated_data.get('transfer_value')
            if int(transfer_value) > user.balance:
                return Response(
                    {"message": "Saldo insuficiente"},
                     status=HTTP_400_BAD_REQUEST
                    )
            elif int(transfer_value) <= 0:
                return Response(
                    {"message": "Digite um valor válido."}, 
                    status=HTTP_400_BAD_REQUEST
                    )
            else:      
                enrollment = serializer.validated_data.get('transfer_user')
                try: 
                    transfer_user = Users.objects.get(enrollment=enrollment)
                except:
                    return Response(
                        {"message": "Código de matrícula inválido"}, 
                        status=HTTP_400_BAD_REQUEST
                        )

                receipt = Receipt (
                    transfer_value = transfer_value,
                    user = user.enrollment,
                    name = user.name,
                    course = user.course,

                    transfer_user = enrollment,  
                    transfer_name = transfer_user.name,
                    transfer_course = transfer_user.course
                )
                receipt.save()

                return Response(serializer.data, status=HTTP_201_CREATED)
        return Response(
            {
                "message": "Há erros de validação", 
                "errors": serializer.errors
            }, 
            status=HTTP_400_BAD_REQUEST
            )
            
# Endpoint to list all receipts
@api_view(['GET'])
def receipt_list(request):
    receipt = Receipt.objects.all()
    serializer = ReceiptSerializer(receipt, many=True)

    return Response(serializer.data)

# Endpoint to list a specefic receipt
@api_view(['GET'])
def receipt_detail(request, pk):
    receipt = get_object_or_404(Receipt, pk=pk)
    serializer = ReceiptSerializer(receipt, many=False)

    return Response(serializer.data)