from django.urls import path
from . import views

urlpatterns = [
    path('', views.api_overview),
    # path('wallet-list/', views.wallet_list),
    # path('wallet-detail/<int:pk>/', views.wallet_detail),
    # path('wallet-create/<int:pk>/', views.wallet_create),
    # path('transfer/<int:pk>/', views.transfer),   
    # path('receipt-list/', views.receipt_list),
    # path('receipt-detail/<int:pk>/', views.receipt_detail)
]