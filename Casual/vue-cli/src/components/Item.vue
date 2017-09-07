<template>
    <div>
        <p> Server Status : {{ status }}</p>
        <button @click="changeStatus">Change Status</button>
    </div>
</template>

<script>
    export default {
        data()  {
            return {
                status : "Offline"
            }
        },
        methods: {
            changeStatus() {
                if(this.status === 'Offline') {
                    this.status = 'Online';
                }
                else {
                    this.status = 'Offline';
                }
            }
        }
    }
</script>

<style>
    
    
</style>