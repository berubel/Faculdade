from django.shortcuts import render
from django.http import JsonResponse


from rest_framework.views import APIView
from rest_framework.views import Response
from rest_framework import generics
from rest_framework import mixins

from .serializers import PostSerializer
from .models import Post
from core import serializers

# Create your views here.

class lib(generics.ListCreateAPIView):
    serializer_class = PostSerializer
    queryset = Post.objects.all()


class myPlantation(generics.ListCreateAPIView):
    serializer_class = PostSerializer
    queryset = Post.objects.all()
