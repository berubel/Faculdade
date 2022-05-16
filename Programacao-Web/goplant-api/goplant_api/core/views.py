from django.http import JsonResponse
from rest_framework import status
from rest_framework.decorators import api_view
from rest_framework.response import Response

from rest_framework.response import Response
from rest_framework import generics

from .serializers import PostSerializer
from .models import Post
from core import serializers

# Create your views here.

class ViewLib(generics.ListAPIView):
    serializer_class = PostSerializer
    queryset = Post.objects.all()


class ViewMyPlantation(generics.ListAPIView):
    serializer_class = PostSerializer
    queryset = Post.objects.all()

class CreateViewLib(generics.ListCreateAPIView):
    serializer_class = PostSerializer
    queryset = Post.objects.all()


class CreateViewMyPlantation(generics.ListCreateAPIView):
    serializer_class = PostSerializer
    queryset = Post.objects.all()

@api_view(['GET', 'PUT', 'DELETE'])
def myPlantationUpdateDelete(request, id):
    try:
        post = Post.objects.get(id=id)
    except Post.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    
    if request.method == 'GET':
        serializer = PostSerializer(post)
        return Response(serializer.data)

    elif request.method == 'PUT':
        serializer = PostSerializer(post, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == 'DELETE':
        post.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)

@api_view(['GET', 'PUT', 'DELETE'])
def libUpdateDelete(request, id):
    try:
        post = Post.objects.get(id=id)
    except Post.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    
    if request.method == 'GET':
        serializer = PostSerializer(post)
        return Response(serializer.data)

    elif request.method == 'PUT':
        serializer = PostSerializer(post, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == 'DELETE':
        post.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)


  

    


