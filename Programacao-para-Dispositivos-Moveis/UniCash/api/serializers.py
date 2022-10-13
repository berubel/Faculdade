from . import models
from rest_framework import serializers

class ReceiptSerializer(serializers.ModelSerializer):
    class Meta:
        model = models.Receipt
        fields = '__all__'

class UsersSerializer(serializers.ModelSerializer):
    class Meta:
        model = models.Users
        fields = '__all__'

