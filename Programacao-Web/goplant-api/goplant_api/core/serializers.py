from rest_framework import serializers

from .models import Post
from django.db import migrations, models

class PostSerializer(serializers.ModelSerializer):
    class Meta:
        model = Post
        fields = (
            'id', 
            'name', 
            'phase',
            'description',
            'temperature',
            'waterByDay',
            'info3s',
            'maturationTime',
        )