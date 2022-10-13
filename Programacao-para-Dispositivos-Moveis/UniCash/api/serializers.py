from . import models
from django.forms import ValidationError
from rest_framework import serializers

class ReceiptSerializer(serializers.ModelSerializer):
    class Meta:
        model = models.Receipt
        fields = '__all__'

class UsersSerializer(serializers.ModelSerializer):
    class Meta:
        model = models.Users
        fields = '__all__'

class TransferDataSerializer(serializers.Serializer):
    transfer_user =  serializers.IntegerField()
    transfer_value = serializers.CharField(max_length=7)

